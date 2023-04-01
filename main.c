#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int x = 10, y = 10; // Starting position of the player
    char key;

    while (1) // Infinite loop to keep the game running
    {
        system("cls"); // Clear the console screen

        // Draw the player at their current position
        for (int i = 0; i < y; i++)
        {
            printf("\n");
        }
        for (int i = 0; i < x; i++)
        {
            printf(" ");
        }
        printf("O\n");

        // Get user input
        if (kbhit()) // Check if a key has been pressed
        {
            key = getch(); // Get the key that was pressed

            // Move the player based on the key that was pressed
            switch (key)
            {
                case 'w':
                    y--;
                    break;
                case 'a':
                    x--;
                    break;
                case 's':
                    y++;
                    break;
                case 'd':
                    x++;
                    break;
            }
        }

        // Wait for a short period of time before redrawing the player
        // to prevent flickering
        for (int i = 0; i < 1000000; i++);

    }

    return 0;
}
