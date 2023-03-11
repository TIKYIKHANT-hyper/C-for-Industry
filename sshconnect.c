//
// Created by Ti Kyi Khant on 3/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <libssh/libssh.h>

int main()
{
    ssh_session my_ssh_session;
    int rc;

    // Initialize the SSH session
    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
    {
        fprintf(stderr, "Error creating SSH session\n");
        exit(1);
    }

    // Set options for the SSH session
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "example.com");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_PORT, 22);
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "username");

    // Connect to the remote host
    rc = ssh_connect(my_ssh_session);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error connecting to remote host: %s\n", ssh_get_error(my_ssh_session));
        ssh_free(my_ssh_session);
        exit(1);
    }

    // Authenticate with the remote host
    rc = ssh_userauth_password(my_ssh_session, NULL, "password");
    if (rc != SSH_AUTH_SUCCESS)
    {
        fprintf(stderr, "Authentication failed: %s\n", ssh_get_error(my_ssh_session));
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(1);
    }

    // Execute a command on the remote host
    ssh_channel channel = ssh_channel_new(my_ssh_session);
    if (channel == NULL)
    {
        fprintf(stderr, "Error creating SSH channel\n");
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(1);
    }
    rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error opening SSH channel: %s\n", ssh_get_error(my_ssh_session));
        ssh_channel_free(channel);
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(1);
    }
    rc = ssh_channel_request_exec(channel, "ls -l");
    if (rc != SSH_OK)
    {
        fprintf(stderr, "Error executing command: %s\n", ssh_get_error(my_ssh_session));
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(1);
    }

    // Read output from the remote command
    char buffer[256];
    int nbytes;
    while ((nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0)) > 0)
    {
        fwrite(buffer, 1, nbytes, stdout);
    }

    // Cleanup and disconnect from the remote host
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);

    return 0;
}
