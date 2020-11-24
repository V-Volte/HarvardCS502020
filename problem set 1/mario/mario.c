//More comfortable version of Mario. Commenting out lines 20 through 22 gives less comfortable version.

#include <stdio.h>
#include <conio.h>

int main () {

    int n;
    printf("Enter the number of pyramid rows: ");
    scanf("%i", &n);

    for (int i = 0; i<n;i++) { //loop, each iteration prints a new row
        for (int j = n - i; j > 0; j--) {//calculating number of blank spaces each line
            printf(" ");
        }
        for (int k = 0; k<=i; k++) {//printing bricks
            printf("#");
        }
        printf(" ");
        for (int l = 0; l <= i; l++) {//printing the right half of bricks
            printf("#");
        }
        printf("\n"); //for each new row to start in a new line
    }

getch();
    return 0;
}
