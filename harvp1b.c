#include <stdio.h>

#include <conio.h>

//Prototyping functions

int length(long long number);
int firsdig(long long num, int dignum);
long long power(long long num, int pow);
int cardtype(long long num);
void nl(void) {
    printf("\n");
}
int getchecksum(long long num);
int getdigit(long long num, int n);
int getrdig(long long num, int n);
int addinddigits(int num);
int testval(long long num);

//main

int main() {

    printf("Enter a number: ");
    long long num;
    scanf("%lli", & num); //Gets credit card number
    testval(num); //tests validity of credit card number

    getch(); //gets character before exiting

}

int length(long long number) { //Finding length

    int i = 0;
    float a = number;
    for (;
        (long long) a > 0; i++) {
        a = a / (float) 10; //Dividing by 10 until number is zero

    }

    return i; //number of iterations of loop is length of number
}

int firsdig(long long num, int dignum) {

    int len = length(num);
    float storage = (float) num / (float)(power(10, 9)); //trimming final 9 digits of the number
    num = (long long) storage;

    if (len > 1) {
        float lange = num / (float)(power(10, len - (9 + dignum)));
        num = (long) lange; //num truncated to first two digits
        return num;
    } else {
        return 0;
    }

}

long long power(long long num, int pow) {

    long long stack = 1;

    for (int i = 0; i < pow; i++) {
        stack = stack * num; //keeps multiplying number with itself i times
    }

    return stack;
}

int cardtype(long long num) {

    int d1 = firsdig(num, 1);
    int d2 = firsdig(num, 2);

    if (length(num) == 13 && d1 == 4) {
        return 1; //VISA
    } else if (length(num) == 15) {
        if (d2 == 34 || d2 == 37) {
            return 2; //AMEX

        } else return 0; //invalid
    } else if (length(num) == 16) {
        if (d1 == 4) {
            return 1; //VISA
        } else if (d2 == 51 || d2 == 52 || d2 == 53 || d2 == 54 || d2 == 55) {
            return 3; //MASTERCARD
        } else return 0; //invalid
    } else return 0; //invalid

}
int getchecksum(long long num) {

    //gets checksum using Luhn's algorithm

    int n1, n2, n3, n4, n5, n6, n7, n8, n9; //store alternate card digits

    //multiply each alternate digit by 2

    n1 = 2 * getrdig(num, 2);
    n2 = 2 * getrdig(num, 4);
    n3 = 2 * getrdig(num, 6);
    n4 = 2 * getrdig(num, 8);
    n5 = 2 * getrdig(num, 10);
    n6 = 2 * getrdig(num, 12);
    n7 = 2 * getrdig(num, 14);
    n8 = 2 * getrdig(num, 16);

    int checksum = 0; //checksum variable

    //adds the individual digits of the alternate digits multiplied by 2

    checksum = addinddigits(n1) + addinddigits(n2) + addinddigits(n3) + addinddigits(n4) + addinddigits(n5) + addinddigits(n6) + addinddigits(n7) + addinddigits(n8);

    //adds the previous sum to the digits that were not multiplied by 2

    checksum += getrdig(num, 1) + getrdig(num, 3) + getrdig(num, 5) + getrdig(num, 7) + getrdig(num, 9) + getrdig(num, 11) + getrdig(num, 13) + getrdig(num, 15);

    //returns checksum

    return checksum;

}

int getdigit(long long num, int n) {

    if (length(num) < n) {
        return 0;
    } else {
        int pos = length(num) - n;
        long long digit = (num % power(10, pos + 1)) - (num % power(10, pos - 1));
        if (length(num % power(10, pos + 1)) == pos) {

            //kinda shouldn't work but still works
            //Checks if the length of the number with digits left of n cut off is less than the length of the number -n.
            //This only returns true if the nth digit is 0

            return 0; //hence returns zero
        } else {

            //In case the nth digit isn't 0

            int diglength = length(digit);

            //divides the number with the power of 10
            //that is less than the position of the digit

            float stack = digit / (float) power(10, length(digit) - 1);

            //and gets the integer part which is the nth digit

            return (int) stack;
        }
    }

}

int getrdig(long long num, int n) {

    if (length(num) < n) {
        return 0;
    } else {
        int pos = n - 1;
        long long digit = (num % power(10, pos + 1)) - (num % power(10, pos - 1));
        if (length(num % power(10, pos + 1)) == pos) {

            //kinda shouldn't work but still works
            //Checks if the length of the number with digits left of n cut off is less than the length of the number -n.
            //This only returns true if the nth digit is 0

            return 0; //hence returns zero
        } else {

            //In case the nth digit isn't 0

            int diglength = length(digit);

            //divides the number with the power of 10
            //that is less than the position of the digit

            float stack = digit / (float) power(10, length(digit) - 1);

            //and gets the integer part which is the nth digit

            return (int) stack;
        }
    }
}

int addinddigits(int num) {
    int stack = 0;
    if (num != 0) {
        for (int i = 1; i <= length(num); i++) {
            stack = stack + getrdig(num, i);
        }
        return stack;
    } else return 0;

}

int testval(long long num) {

    int typeofcard = cardtype(num);

    if (getchecksum(num) % 10 == 0) {
        if (typeofcard == 1) {
            printf("\nVISA");
        } else if (typeofcard == 2) {
            printf("\nAMERICAN EXPRESS");
        } else if (typeofcard == 3) {
            printf("\nMASTERCARD");
        } else printf("INVALID CARD.");
    } else {
        printf("INVALID CARD");
    }
    return 0;
}