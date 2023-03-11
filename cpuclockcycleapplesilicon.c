//
// Created by Ti Kyi Khant on 3/11/2023.
//
#include <stdio.h>
#include <sys/sysctl.h>

int main() {
    int clock_rate;
    size_t len = sizeof(clock_rate);
    sysctlbyname("machdep.cpu.brand_string", &clock_rate, &len, NULL, 0);
    printf("Clock Rate: %d\n", clock_rate);
    return 0;
}
