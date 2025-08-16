#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Open Network Connections:\n");
    system("netstat -tunap");
    return 0;
}
