#include <stdio.h>
#include "NumClass.h"

 int orgNum;  //the original number from the input
 int reverNum;  //the starter for the reversed number

double pow(double num, double powerNum) {
    if (powerNum == 0) {
        return 1.0;  // x^0 is always 1
    }

    double result = 1.0;
    while (powerNum > 0) {
        result *= num;
        --powerNum;
    }

    return result;
}


// Function to count the number of digits in a number
int countDigits(int num) {
    if (num == 0) {
        return 1; // Base case: return 1 when num is 0
    } else {
        return 1 + countDigits(num / 10); // Recursive call to count remaining digits
    }
}


// Recursive function to check if a number is an Armstrong number
int isArmstrong2(int num, int originalNum, int poweredSum) {
    if (num == 0) {
        return poweredSum;
    } else {
        int remainder = num % 10;
        int digitCount = countDigits(originalNum);
        int poweredDigit = (int)pow(remainder, digitCount);
        return isArmstrong2(num / 10, originalNum, poweredSum + poweredDigit);
    }
}

// Function to check if a number is an Armstrong number
int isArmstrongRec(int num) {
    int poweredSum = isArmstrong2(num, num, 0);
    return poweredSum == num;
}

// Function to check if a number is a palindrome
int isPalindrome2(int num, int originalNum) {
    if (num == 0) {
        return originalNum;
    } else {
        int remainder = num % 10;
        originalNum = originalNum * 10 + remainder;
        return isPalindrome2(num / 10, originalNum);
    }
}

// Wrapper function to check if a number is a palindrome
int isPalindromeRec(int num) {
    return (num == isPalindrome2(num, 0));
}

