#include <stdio.h>
#include <conio.h>

int main () {

    int n;
    printf("Enter the number of pyramid rows: ");
    scanf("%i", &n);

    for (int i = 0; i<n;i++) {
        for (int j = n - i; j > 0; j--) {
            printf(" ");
        }
        for (int k = 0; k<=i; k++) {
            printf("#");
        }
        printf(" ");
        for (int l = 0; l <= i; l++) {
            printf("#");
        }
        printf("\n");
    }

getch();
    return 0;
}
