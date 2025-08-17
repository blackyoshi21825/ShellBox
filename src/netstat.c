#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Open Network Connections:\n");
    
#ifdef _WIN32
    if (system("netstat -an") != 0) {
        printf("Error: Unable to retrieve network information on Windows.\n");
        return 1;
    }
#elif __APPLE__
    if (system("netstat -an") != 0) {
        printf("Error: Unable to retrieve network information on macOS.\n");
        return 1;
    }
#else
    if (system("ss -tuln 2>/dev/null") == 0) {
        return 0;
    } else if (system("netstat -tuln 2>/dev/null") == 0) {
        return 0;
    } else {
        printf("\nTCP Connections:\n");
        system("cat /proc/net/tcp 2>/dev/null || echo 'TCP info not available'");
        printf("\nUDP Connections:\n");
        system("cat /proc/net/udp 2>/dev/null || echo 'UDP info not available'");
    }
#endif
    
    return 0;
}
