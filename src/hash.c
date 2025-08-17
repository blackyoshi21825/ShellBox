#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple checksum calculator using system commands
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file> [md5|sha256]\n", argv[0]);
        return 1;
    }
    
    const char *filename = argv[1];
    const char *type = argc > 2 ? argv[2] : "md5";
    char command[512];
    
    if (strcmp(type, "sha256") == 0) {
        snprintf(command, sizeof(command), "shasum -a 256 '%s'", filename);
    } else {
        snprintf(command, sizeof(command), "md5 '%s'", filename);
    }
    
    return system(command);
}