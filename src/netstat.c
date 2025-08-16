#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Open Network Connections:\n");
    
#ifdef _WIN32
    // Windows: use netstat (usually available)
    if (system("netstat -an") != 0) {
        printf("Error: Unable to retrieve network information on Windows.\n");
        return 1;
    }
#else
    // Linux/Unix: try multiple approaches
    if (system("ss -tuln 2>/dev/null") == 0) {
        // ss is modern replacement for netstat
        return 0;
    } else if (system("netstat -tuln 2>/dev/null") == 0) {
        // fallback to netstat
        return 0;
    } else {
        // Last resort: check /proc/net
        printf("\nTCP Connections:\n");
        system("cat /proc/net/tcp 2>/dev/null || echo 'TCP info not available'");
        printf("\nUDP Connections:\n");
        system("cat /proc/net/udp 2>/dev/null || echo 'UDP info not available'");
    }
#endif
    
    return 0;
}
