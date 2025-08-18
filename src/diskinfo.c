#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#ifdef __APPLE__
#include <sys/mount.h>
#elif __linux__
#include <mntent.h>
#include <sys/vfs.h>
#endif

#define RESET "\033[0m"
#define GREEN "\033[92m"
#define YELLOW "\033[93m"
#define CYAN "\033[96m"

void format_bytes(unsigned long long bytes, char *result) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit = 0;
    double size = bytes;
    
    while (size >= 1024 && unit < 4) {
        size /= 1024;
        unit++;
    }
    
    if (unit == 0) {
        sprintf(result, "%.0f %s", size, units[unit]);
    } else {
        sprintf(result, "%.1f %s", size, units[unit]);
    }
}

void print_disk_info() {
    printf(GREEN "Disk Information:\n" RESET);
    printf("%-20s %-10s %-10s %-10s %-10s %-6s %s\n", 
           "Filesystem", "Type", "Size", "Used", "Avail", "Use%", "Mounted on");
    printf("%.80s\n", "--------------------------------------------------------------------------------");

#ifdef __APPLE__
    struct statfs *mounts;
    int count = getmntinfo(&mounts, MNT_NOWAIT);
    
    for (int i = 0; i < count; i++) {
        struct statvfs vfs;
        if (statvfs(mounts[i].f_mntonname, &vfs) == 0) {
            unsigned long long total = vfs.f_blocks * vfs.f_frsize;
            unsigned long long free = vfs.f_bavail * vfs.f_frsize;
            unsigned long long used = total - (vfs.f_bfree * vfs.f_frsize);
            int use_percent = total > 0 ? (used * 100) / total : 0;
            
            char total_str[20], used_str[20], free_str[20];
            format_bytes(total, total_str);
            format_bytes(used, used_str);
            format_bytes(free, free_str);
            
            printf("%-20s %-10s %-10s %-10s %-10s %s%3d%%%s %s\n",
                   mounts[i].f_mntfromname, mounts[i].f_fstypename,
                   total_str, used_str, free_str,
                   use_percent > 80 ? YELLOW : "", use_percent, RESET,
                   mounts[i].f_mntonname);
        }
    }
#elif __linux__
    FILE *fp = setmntent("/proc/mounts", "r");
    if (fp) {
        struct mntent *entry;
        while ((entry = getmntent(fp)) != NULL) {
            if (strncmp(entry->mnt_fsname, "/dev/", 5) == 0 || 
                strcmp(entry->mnt_type, "tmpfs") == 0) {
                struct statvfs vfs;
                if (statvfs(entry->mnt_dir, &vfs) == 0) {
                    unsigned long long total = vfs.f_blocks * vfs.f_frsize;
                    unsigned long long free = vfs.f_bavail * vfs.f_frsize;
                    unsigned long long used = total - (vfs.f_bfree * vfs.f_frsize);
                    int use_percent = total > 0 ? (used * 100) / total : 0;
                    
                    char total_str[20], used_str[20], free_str[20];
                    format_bytes(total, total_str);
                    format_bytes(used, used_str);
                    format_bytes(free, free_str);
                    
                    printf("%-20s %-10s %-10s %-10s %-10s %s%3d%%%s %s\n",
                           entry->mnt_fsname, entry->mnt_type,
                           total_str, used_str, free_str,
                           use_percent > 80 ? YELLOW : "", use_percent, RESET,
                           entry->mnt_dir);
                }
            }
        }
        endmntent(fp);
    }
#endif
}

int main() {
    print_disk_info();
    return 0;
}