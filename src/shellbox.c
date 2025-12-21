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
    printf("    ci (cpuinfo), mi (meminfo), ns (netstat), up (uptime), di (diskinfo), si (sys-info)\n");
    printf("  File Operations:\n");
    printf("    fs (file-search), fi (file-info), fd (find-duplicates), ct (copytree), dt (deltree)\n");
    printf("  Text Processing:\n");
    printf("    gr (grep), ha (hash)\n");
    printf("  System Tools:\n");
    printf("    bk (backup), du (disk-usage), pl (process-list), pc (port-check), ni (network-info)\n");
    printf("  Development Tools:\n");
    printf("    en (encode), js (json), gs (git-stats)\n");
    printf("  Security Tools:\n");
    printf("    nm (nmap-scan), se (subdomain-enum), db (dir-brute), hc (hash-crack), ws (wifi-scan), bg (banner-grab)\n");
    printf("  Flags:\n");
    printf("    !verbose, !quiet, !debug, !stealth, !fast, !aggressive\n");
    printf("  Other:\n");
    printf("    help, clear, exit\n\n");
}

void print_flags()
{
    printf(GREEN "Available Flags:\n" RESET);
    printf("  !verbose   - Enable verbose output for commands\n");
    printf("  !quiet     - Suppress non-essential output\n");
    printf("  !debug     - Enable debug mode with detailed logs\n");
    printf("  !stealth   - Use stealth mode for security tools\n");
    printf("  !fast      - Use fast/quick scan modes\n");
    printf("  !aggressive- Use aggressive scanning (use with caution)\n");
    printf("  !reset     - Reset all flags to default\n");
    printf("  !status    - Show current flag status\n\n");
}

// Global flag variables
int flag_verbose = 0;
int flag_quiet = 0;
int flag_debug = 0;
int flag_stealth = 0;
int flag_fast = 0;
int flag_aggressive = 0;

void handle_flag(char *flag)
{
    if (strcmp(flag, "!verbose") == 0) {
        flag_verbose = !flag_verbose;
        printf("Verbose mode: %s\n", flag_verbose ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!quiet") == 0) {
        flag_quiet = !flag_quiet;
        printf("Quiet mode: %s\n", flag_quiet ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!debug") == 0) {
        flag_debug = !flag_debug;
        printf("Debug mode: %s\n", flag_debug ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!stealth") == 0) {
        flag_stealth = !flag_stealth;
        printf("Stealth mode: %s\n", flag_stealth ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!fast") == 0) {
        flag_fast = !flag_fast;
        printf("Fast mode: %s\n", flag_fast ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!aggressive") == 0) {
        flag_aggressive = !flag_aggressive;
        printf("Aggressive mode: %s\n", flag_aggressive ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!reset") == 0) {
        flag_verbose = flag_quiet = flag_debug = flag_stealth = flag_fast = flag_aggressive = 0;
        printf("All flags reset to default\n");
    }
    else if (strcmp(flag, "!status") == 0) {
        printf("Flag Status:\n");
        printf("  Verbose: %s\n", flag_verbose ? "ON" : "OFF");
        printf("  Quiet: %s\n", flag_quiet ? "ON" : "OFF");
        printf("  Debug: %s\n", flag_debug ? "ON" : "OFF");
        printf("  Stealth: %s\n", flag_stealth ? "ON" : "OFF");
        printf("  Fast: %s\n", flag_fast ? "ON" : "OFF");
        printf("  Aggressive: %s\n", flag_aggressive ? "ON" : "OFF");
    }
    else if (strcmp(flag, "!help") == 0) {
        print_flags();
    }
    else {
        printf("Unknown flag: %s\nType '!help' for available flags\n", flag);
    }
}

char* get_flag_env()
{
    static char env_flags[256];
    snprintf(env_flags, sizeof(env_flags), 
        "SB_VERBOSE=%d SB_QUIET=%d SB_DEBUG=%d SB_STEALTH=%d SB_FAST=%d SB_AGGRESSIVE=%d",
        flag_verbose, flag_quiet, flag_debug, flag_stealth, flag_fast, flag_aggressive);
    return env_flags;
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

    // Handle flags
    if (cmd[0] == '!')
    {
        handle_flag(cmd);
        return;
    }

    // Try to run as Shell Box command
    if (strstr(cmd, "sb-") == cmd ||
        strcmp(cmd, "cpuinfo") == 0 || strcmp(cmd, "ci") == 0 ||
        strcmp(cmd, "meminfo") == 0 || strcmp(cmd, "mi") == 0 ||
        strcmp(cmd, "netstat") == 0 || strcmp(cmd, "ns") == 0 ||
        strcmp(cmd, "uptime") == 0 || strcmp(cmd, "up") == 0 ||
        strcmp(cmd, "diskinfo") == 0 || strcmp(cmd, "di") == 0 ||
        strcmp(cmd, "file-search") == 0 || strcmp(cmd, "fs") == 0 ||
        strcmp(cmd, "file-info") == 0 || strcmp(cmd, "fi") == 0 ||
        strcmp(cmd, "find-duplicates") == 0 || strcmp(cmd, "fd") == 0 ||
        strcmp(cmd, "copytree") == 0 || strcmp(cmd, "ct") == 0 ||
        strcmp(cmd, "deltree") == 0 || strcmp(cmd, "dt") == 0 ||
        strcmp(cmd, "grep") == 0 || strcmp(cmd, "gr") == 0 ||
        strcmp(cmd, "hash") == 0 || strcmp(cmd, "ha") == 0 ||
        strcmp(cmd, "nmap-scan") == 0 || strcmp(cmd, "nm") == 0 ||
        strcmp(cmd, "subdomain-enum") == 0 || strcmp(cmd, "se") == 0 ||
        strcmp(cmd, "dir-brute") == 0 || strcmp(cmd, "db") == 0 ||
        strcmp(cmd, "hash-crack") == 0 || strcmp(cmd, "hc") == 0 ||
        strcmp(cmd, "wifi-scan") == 0 || strcmp(cmd, "ws") == 0 ||
        strcmp(cmd, "banner-grab") == 0 || strcmp(cmd, "bg") == 0)
    {
        // Convert short aliases to full command names
        char full_command[64];
        if (strcmp(cmd, "ci") == 0) strcpy(full_command, "cpuinfo");
        else if (strcmp(cmd, "mi") == 0) strcpy(full_command, "meminfo");
        else if (strcmp(cmd, "ns") == 0) strcpy(full_command, "netstat");
        else if (strcmp(cmd, "up") == 0) strcpy(full_command, "uptime");
        else if (strcmp(cmd, "di") == 0) strcpy(full_command, "diskinfo");
        else if (strcmp(cmd, "fs") == 0) strcpy(full_command, "file-search");
        else if (strcmp(cmd, "fi") == 0) strcpy(full_command, "file-info");
        else if (strcmp(cmd, "fd") == 0) strcpy(full_command, "find-duplicates");
        else if (strcmp(cmd, "ct") == 0) strcpy(full_command, "copytree");
        else if (strcmp(cmd, "dt") == 0) strcpy(full_command, "deltree");
        else if (strcmp(cmd, "gr") == 0) strcpy(full_command, "grep");
        else if (strcmp(cmd, "ha") == 0) strcpy(full_command, "hash");
        else if (strcmp(cmd, "nm") == 0) strcpy(full_command, "nmap-scan");
        else if (strcmp(cmd, "se") == 0) strcpy(full_command, "subdomain-enum");
        else if (strcmp(cmd, "db") == 0) strcpy(full_command, "dir-brute");
        else if (strcmp(cmd, "hc") == 0) strcpy(full_command, "hash-crack");
        else if (strcmp(cmd, "ws") == 0) strcpy(full_command, "wifi-scan");
        else if (strcmp(cmd, "bg") == 0) strcpy(full_command, "banner-grab");
        else strcpy(full_command, cmd);
        
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
            snprintf(full_cmd, sizeof(full_cmd), "%s/sb-%s", shellbox_path, full_command);
        }
        else
        {
            snprintf(full_cmd, sizeof(full_cmd), "./bin/sb-%s", full_command);
        }
        if (access(full_cmd, F_OK) == 0)
        {
            char env_cmd[1024];
            snprintf(env_cmd, sizeof(env_cmd), "%s %s", get_flag_env(), full_cmd);
            system(env_cmd);
        }
        else
        {
            if (len != -1)
            {
                snprintf(full_cmd, sizeof(full_cmd), "%s/%s", shellbox_path, full_command);
            }
            else
            {
                snprintf(full_cmd, sizeof(full_cmd), "./bin/%s", full_command);
            }
            if (access(full_cmd, F_OK) == 0)
            {
                char env_cmd[1024];
                snprintf(env_cmd, sizeof(env_cmd), "%s %s", get_flag_env(), full_cmd);
                system(env_cmd);
            }
            else
            {
                printf("Command not found: %s\n", cmd);
            }
        }
    }
    else
    {
        // Convert short aliases to full command names for scripts
        char script_cmd[64];
        if (strcmp(cmd, "si") == 0) strcpy(script_cmd, "sys-info");
        else if (strcmp(cmd, "bk") == 0) strcpy(script_cmd, "backup");
        else if (strcmp(cmd, "du") == 0) strcpy(script_cmd, "disk-usage");
        else if (strcmp(cmd, "pl") == 0) strcpy(script_cmd, "process-list");
        else if (strcmp(cmd, "pc") == 0) strcpy(script_cmd, "port-check");
        else if (strcmp(cmd, "ni") == 0) strcpy(script_cmd, "network-info");
        else if (strcmp(cmd, "en") == 0) strcpy(script_cmd, "encode");
        else if (strcmp(cmd, "js") == 0) strcpy(script_cmd, "json");
        else if (strcmp(cmd, "gs") == 0) strcpy(script_cmd, "git-stats");
        else strcpy(script_cmd, cmd);
        
        // Try shell scripts - convert dashes to underscores
        char script_name[256];
        strcpy(script_name, script_cmd);
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
            char env_cmd[1024];
            if (len != -1)
            {
                snprintf(env_cmd, sizeof(env_cmd), "%s bash %s/scripts/%s.sh", get_flag_env(), base_path, script_name);
            }
            else
            {
                snprintf(env_cmd, sizeof(env_cmd), "%s bash ./scripts/%s.sh", get_flag_env(), script_name);
            }
            system(env_cmd);
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