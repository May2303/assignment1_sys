  #include <stdio.h>
  #include "NumClass.h"
  //#include "advancedClassificationLoop.c"
   

int main(){
    
    int num1;
    int num2;


    scanf("%d", &num1);
    scanf("%d", &num2);


    // Prime numbers between num1 and num2
    printf("prime number between 2 nums:");

    for (int i = num1; i <= num2; ++i) {
        if (isPrime(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");

    // Strong numbers between num1 and num2
    printf("strong number between 2 nums:");
    for (int i = num1; i <= num2; ++i) {
        if (isStrong(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    
    //palindrome numbers between num1 and num2
    printf("strong number between 2 nums:");
    for (int i = num1; i <= num2; ++i) {
        if (isPalindrome(i)) {
            printf(" %d", i);
        }
    }
    printf("\n");
    

    

return 0;

}
