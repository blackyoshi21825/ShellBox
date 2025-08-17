#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define RESET "\033[0m"
#define GREEN "\033[92m"

void print_banner()
{
    printf("\033[2J\033[H");
    printf(GREEN);
    printf(" ____  _          _ _ ____            \n");
    printf("/ ___|| |__   ___| | | __ )  _____  __\n");
    printf("\\___ \\| '_ \\ / _ \\ | |  _ \\ / _ \\ \\/ /\n");
    printf(" ___) | | | |  __/ | | |_) | (_) >  < \n");
    printf("|____/|_| |_|\\___|_|_|____/ \\___/_/\\_\\\n");
    printf("\nWelcome to ShellBox - Cross-platform utility suite\n");
    printf("Type 'help' for commands, 'exit' to quit\n\n");
    printf(RESET);
}

void print_help()
{
    printf(GREEN "Available Commands:\n" RESET);
    printf("  System Info:\n");
    printf("    cpuinfo, meminfo, netstat, uptime, sys-info\n");
    printf("  File Operations:\n");
    printf("    file-search, file-info, find-duplicates, copytree, deltree\n");
    printf("  Text Processing:\n");
    printf("    grep, hash\n");
    printf("  System Tools:\n");
    printf("    backup, disk-usage, process-list, port-check, network-info\n");
    printf("  Development Tools:\n");
    printf("    encode, json, git-stats\n");
    printf("  Other:\n");
    printf("    help, clear, exit\n\n");
}

void execute_command(char *cmd)
{
    char full_cmd[512];

    if (strcmp(cmd, "help") == 0)
    {
        print_help();
        return;
    }

    if (strcmp(cmd, "clear") == 0)
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        print_banner();
        return;
    }

    if (strcmp(cmd, "exit") == 0)
    {
        printf(GREEN "Goodbye!\n" RESET);
        exit(0);
    }

    // Try to run as Shell Box command
    if (strstr(cmd, "sb-") == cmd ||
        strcmp(cmd, "cpuinfo") == 0 || strcmp(cmd, "meminfo") == 0 ||
        strcmp(cmd, "netstat") == 0 || strcmp(cmd, "uptime") == 0 ||
        strcmp(cmd, "file-search") == 0 || strcmp(cmd, "file-info") == 0 ||
        strcmp(cmd, "find-duplicates") == 0 || strcmp(cmd, "copytree") == 0 ||
        strcmp(cmd, "deltree") == 0 || strcmp(cmd, "grep") == 0 ||
        strcmp(cmd, "hash") == 0)
    {
        // Get the directory where shellbox is located
        char shellbox_path[512];
        ssize_t len = readlink("/proc/self/exe", shellbox_path, sizeof(shellbox_path) - 1);
        if (len != -1)
        {
            shellbox_path[len] = '\0';
            char *last_slash = strrchr(shellbox_path, '/');
            if (last_slash)
            {
                *last_slash = '\0'; // Remove /shellbox, now points to /bin
            }
            snprintf(full_cmd, sizeof(full_cmd), "%s/sb-%s", shellbox_path, cmd);
        }
        else
        {
            snprintf(full_cmd, sizeof(full_cmd), "./bin/sb-%s", cmd);
        }
        if (access(full_cmd, F_OK) == 0)
        {
            system(full_cmd);
        }
        else
        {
            if (len != -1)
            {
                snprintf(full_cmd, sizeof(full_cmd), "%s/%s", shellbox_path, cmd);
            }
            else
            {
                snprintf(full_cmd, sizeof(full_cmd), "./bin/%s", cmd);
            }
            if (access(full_cmd, F_OK) == 0)
            {
                system(full_cmd);
            }
            else
            {
                printf("Command not found: %s\n", cmd);
            }
        }
    }
    else
    {
        // Try shell scripts - convert dashes to underscores
        char script_name[256];
        strcpy(script_name, cmd);
        for (int i = 0; script_name[i]; i++)
        {
            if (script_name[i] == '-')
                script_name[i] = '_';
        }
        // Get the directory where shellbox is located
        char shellbox_path[512];
        char base_path[512];
        ssize_t len = readlink("/proc/self/exe", shellbox_path, sizeof(shellbox_path) - 1);
        if (len != -1)
        {
            shellbox_path[len] = '\0';
            strcpy(base_path, shellbox_path);
            char *last_slash = strrchr(base_path, '/');
            if (last_slash)
            {
                *last_slash = '\0'; // Remove /shellbox
                last_slash = strrchr(base_path, '/');
                if (last_slash)
                {
                    *last_slash = '\0'; // Remove /bin
                }
            }
            snprintf(full_cmd, sizeof(full_cmd), "%s/scripts/%s.sh", base_path, script_name);
        }
        else
        {
            snprintf(full_cmd, sizeof(full_cmd), "./scripts/%s.sh", script_name);
        }
        if (access(full_cmd, F_OK) == 0)
        {
            if (len != -1)
            {
                snprintf(full_cmd, sizeof(full_cmd), "bash %s/scripts/%s.sh", base_path, script_name);
            }
            else
            {
                snprintf(full_cmd, sizeof(full_cmd), "bash ./scripts/%s.sh", script_name);
            }
            system(full_cmd);
        }
        else
        {
            printf("Command not found: %s\n", cmd);
        }
    }
}

int main()
{
    char input[MAX_CMD_LEN];

    print_banner();

    while (1)
    {
        printf(GREEN "shellbox>" RESET " ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0)
        {
            continue;
        }

        execute_command(input);
    }

    return 0;
}