#include <stdio.h>
#include "NumClass.h"

int isPalindrome(int num) {
     int orgNum = num;   // Store the original number
    int reverNum = 0;   // Initialize the reversed number

    while (num > 0) {
        reverNum = reverNum * 10 + num % 10;
        num = num / 10;
    }

    return (reverNum == orgNum);  // Return 1 if palindrome, 0 otherwise
}


int isArmstrong(int num) {
return 0; // Return 1 if Armstrong, 0 otherwise
}
