#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Memory Info:\n");
#ifdef __APPLE__
    printf("Total: ");
    system("sysctl -n hw.memsize | awk '{print $1/1024/1024/1024 \" GB\"}'");
    system("vm_stat | head -5");
#elif __linux__
    system("free -h");
#else
    printf("Memory info not available on this platform\n");
#endif
    return 0;
}
