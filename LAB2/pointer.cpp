
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Palindrome number 
int palindrome(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* reversed = (int*)malloc(sizeof(int));
    int* temp = (int*)malloc(sizeof(int));

    if (!original || !reversed || !temp) {
        printf("Memory allocation failed\n");
        return 0;
    }

    *original = *num;
    *reversed = 0;
    *temp = *num;

    while (*temp != 0) {
        *reversed = (*reversed * 10) + (*temp % 10);
        *temp /= 10;
    }

    int isPalindrome = (*original == *reversed);

    
    free(original);
    free(reversed);
    free(temp);

    return isPalindrome;
}

// Armstrong number 
int armstrongNumber(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* result = (int*)malloc(sizeof(int));
    int* digits = (int*)malloc(sizeof(int));
    int* remainder = (int*)malloc(sizeof(int));
    if (!original || !result || !digits || !remainder) {
        printf("Memory allocation failed\n");
        return 0;
    }

    *original = *num;
    *result = 0;
    *digits = 0;

    while (*original != 0) {
       *original /= 10;
        (*digits)++;
    }

   *original = *num;
    while( *original != 0) {
        *remainder = *original % 10;
        *result += pow(*remainder, *digits);
       *original /= 10;
    }

    int isArmstrong = (*num == *result);

    free(original);
    free(result);
    free(digits);
    free(remainder);

    return isArmstrong;
}

// Perfect number 
int perfectNumber(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* sum = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));
    if (!original || !sum) {
        printf("Memory allocation failed\n");
        return 0;
    }

    *original = *num;
    *sum = 0;

    for (*i = 1; *i <= (*original) / 2 ; (*i)++) {
        if (*original % *i == 0){
            *sum += *i;
        }
    }

    int isPerfect = (*original == *sum);

    free(original);
    free(sum);

    return isPerfect;
}

int main() {
    int* num = (int*)malloc(sizeof(int));
    int* choice = (int*)malloc(sizeof(int));

    if (!num || !choice) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\n    MENU    \n");
        printf("1. Palindrome\n");
        printf("2. Armstrong Number\n");
        printf("3. Perfect Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);

        if (*choice == 1 || *choice == 2 || *choice == 3) {
            printf("Enter the number: ");
            scanf("%d", num);

            switch (*choice) {
                case 1:
                    if (palindrome(num))
                        printf("%d is a palindrome.\n", *num);
                    else
                        printf("%d is not a palindrome.\n", *num);
                    break;
                case 2:
                    if (armstrongNumber(num))
                        printf("%d is an Armstrong number.\n", *num);
                    else
                        printf("%d is not an Armstrong number.\n", *num);
                    break;
                case 3:
                    if (perfectNumber(num))
                        printf("%d is a perfect number.\n", *num);
                    else
                        printf("%d is not a perfect number.\n", *num);
                    break;
            }
        } else if (*choice != 4) {
            printf("Invalid choice, please choose from the menu\n");
        }

    } while (*choice != 4);

    printf("Exiting program...\n");

    free(num);
    free(choice);

    return 0;
}