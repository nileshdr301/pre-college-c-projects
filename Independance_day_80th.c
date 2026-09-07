#include <stdio.h>

int main() {
    int i, j;

    printf("|========================================|\n");
    printf("|  HAPPY 80th INDEPENDENCE DAY, INDIA!   |\n");
    printf("|========================================|\n\n");

    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 40; j++) {
            printf("\033[41m \033[0m"); 
        }
        printf("\n");
    }

   
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 40; j++) {
            if (i == 2 && j == 20) {
                printf("\033[47m\033[34mO\033[0m"); 
            } else {
                printf("\033[47m \033[0m"); 
            }
        }
        printf("\n");
    }

  
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 40; j++) {
            printf("\033[42m \033[0m"); 
        }
        printf("\n");
    }

    printf("\n========================================\n");
    return 0;
}
