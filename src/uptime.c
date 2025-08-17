#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __APPLE__
#include <sys/sysctl.h>
#include <sys/types.h>
#elif __linux__
#include <sys/sysinfo.h>
#endif

int main() {
#ifdef __APPLE__
    struct timeval boottime;
    size_t len = sizeof(boottime);
    if (sysctlbyname("kern.boottime", &boottime, &len, NULL, 0) == 0) {
        time_t now;
        time(&now);
        long uptime_seconds = now - boottime.tv_sec;
        
        int days = uptime_seconds / 86400;
        int hours = (uptime_seconds % 86400) / 3600;
        int minutes = (uptime_seconds % 3600) / 60;
        
        printf("Uptime: %d days, %d hours, %d minutes\n", days, hours, minutes);
    }
#elif __linux__
    struct sysinfo info;
    if (sysinfo(&info) == 0) {
        long uptime_seconds = info.uptime;
        
        int days = uptime_seconds / 86400;
        int hours = (uptime_seconds % 86400) / 3600;
        int minutes = (uptime_seconds % 3600) / 60;
        
        printf("Uptime: %d days, %d hours, %d minutes\n", days, hours, minutes);
        printf("Load averages: %.2f, %.2f, %.2f\n", 
               info.loads[0]/65536.0, info.loads[1]/65536.0, info.loads[2]/65536.0);
    }
#else
    printf("Uptime not supported on this platform\n");
#endif
    
    return 0;
}