#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("CPU Info:\n");
#ifdef __APPLE__
    system("sysctl -n machdep.cpu.brand_string");
    printf("Cores: ");
    system("sysctl -n hw.ncpu");
#elif __linux__
    system("lscpu");
#else
    printf("CPU info not available on this platform\n");
#endif
    return 0;
}
