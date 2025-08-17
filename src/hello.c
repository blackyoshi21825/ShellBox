#include <stdio.h>

#define RESET "\033[0m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

int main()
{
    printf(CYAN "┌─────────────────────────┐\n" RESET);
    printf(CYAN "│ " GREEN "Hello from Shell Box!" CYAN " │\n" RESET);
    printf(CYAN "└─────────────────────────┘\n" RESET);
    printf(YELLOW "Welcome to the Shell Box utility suite!\n" RESET);
    return 0;
}
