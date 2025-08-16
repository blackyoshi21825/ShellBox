#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <pattern>\n", argv[0]);
        return 1;
    }
    char command[256];
    snprintf(command, sizeof(command), "find . -name '%s'", argv[1]);
    system(command);
    return 0;
}
