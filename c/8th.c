#include <stdio.h>
#include <stdbool.h>

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}

bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void displayPrimes(int lower, int upper) {
    printf("Prime numbers between %d and %d are:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isPrime(i))
            printf("%d ", i);
    }
    printf("\n");
}

void decimalToBinary(int num) {
    if (num > 1)
        decimalToBinary(num / 2);
    printf("%d", num % 2);
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Calculate the power of a number.\n");
        printf("2. Display all prime numbers between two intervals.\n");
        printf("3. Convert decimal number to binary.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int base, exponent;
                printf("Enter base: ");
                scanf("%d", &base);
                printf("Enter exponent: ");
                scanf("%d", &exponent);
                printf("%d^%d = %d\n", base, exponent, power(base, exponent));
                break;
            }
            case 2: {
                int lower, upper;
                printf("Enter lower interval: ");
                scanf("%d", &lower);
                printf("Enter upper interval: ");
                scanf("%d", &upper);
                displayPrimes(lower, upper);
                break;
            }
            case 3: {
                int num;
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                printf("Binary representation of %d is: ", num);
                if (num == 0) {
                    printf("0");
                } else {
                    decimalToBinary(num);
                }
                printf("\n");
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
