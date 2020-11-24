#include <stdio.h>
#include <conio.h>

//Prototyping functions

int length(long long number);
long long power(long long num, int pow);
int cardType(long long num);
int getChecksum(long long num);
int getDigit(long long num, int n);
int addDigits(int num);
int testValue(long long num);

//main

int main() {

  printf("Enter a number: ");
  long long num;
  scanf("%lli", & num); //Gets credit card number
  testValue(num); //tests validity of credit card number
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

long long power(long long num, int pow) { //defining power function because ^ doesn't look good and I'm trying to only use <stdio.h>

  long long stack = 1;

  for (int i = 0; i < pow; i++) {
    stack = stack * num; //keeps multiplying number with itself i times
  }

  return stack;
}

int cardType(long long num) {

  int d1 = getDigit(num, length(num));
  int d2 = (d1 * 10) + getDigit(num, length(num) - 1);

  if (length(num) == 13 && d1 == 4) {
    return 1; //VISA
  } else if (length(num) == 15) {
    if (d2 == 34 || d2 == 37) {
      return 2; //AMEX

    } else return 0; //invalid
  } else if (length(num) == 16) {
    if (d1 == 4) {
      return 1; //VISA
    } else if (d2 > 50 && d2 < 56) {
      return 3; //MASTERCARD
    } else return 0; //invalid
  } else return 0; //invalid

}
int getChecksum(long long num) {

  //gets checksum using Luhn's algorithm

  int checksum = 0;

  for (int i = 2; i <= length(num); i += 2) {
    checksum += addDigits(getDigit(num, i) * 2); //Adds the sum of the individual digits of each even digit multiplied by 2
  }

  for (int i = 1; i <= length(num); i += 2) {
    checksum += getDigit(num, i); //Adds the previous sum to the sum off all odd digits
  }

  return checksum;

}

int getDigit(long long num, int n) { //Gets the nth digit from the last

  if (length(num) < n) {
    return 0;
  } else {
    int pos = n - 1;
    long long digit = (num % power(10, pos + 1)) - (num % power(10, pos - 1)); //Removes all numbers to the left of the digit
    if (length(num % power(10, pos + 1)) == pos) { //only evaluates true if the digit is 0, or else the length would be one more
      return 0; //hence returns zero
    } else { //in case isn't 0
      int diglength = length(digit);
      float stack = digit / (float) power(10, length(digit) - 1);
      return (int) stack; //returns the digit removing all the numbers to the right of it
    }
  }
}

int addDigits(int num) { //adds the individual digits of a number
  int stack = 0;
  if (num == 0) {
    return 0;
  } else {
    for (int i = 1; i <= length(num); i++) {
      stack = stack + getDigit(num, i);
    }
    return stack;
  }
}

int testValue(long long num) { //tests the card number

  if (getChecksum(num) % 10 == 0) { //testing Luhn's algorithm
    if (cardType(num) == 1) { //checking the value of the first digits
      printf("\nVISA");
    } else if (cardType(num) == 2) {
      printf("\nAMERICAN EXPRESS");
    } else if (cardType(num) == 3) {
      printf("\nMASTERCARD");
    } else printf("INVALID CARD.");
  } else {
    printf("INVALID CARD");
  }
  return 0;

}
