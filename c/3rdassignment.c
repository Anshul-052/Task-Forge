#include <stdio.h>
int main() {
    int choice, num, i, factorial = 1, prime = 1;

    printf("Choose an option:\n");
    printf("1. Calculate Factorial\n");
    printf("2. Check if Prime Number\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number to calculate its factorial: ");
            scanf("%d", &num);

            if (num < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else { 
                factorial = 1; 
                for (i = 1; i <= num; i++) {
                    factorial *= i;
                }
                printf("Factorial of %d is %d\n", num, factorial);
            }
            break;

        case 2:
            printf("Enter a number to check if it's prime: ");
            scanf("%d", &num);

            if (num <= 1) {
                printf("%d is not a prime number.\n", num);
            } else {
                prime = 1; 
                for (i = 2; i * i <= num; i++) {  
                    if (num % i == 0) { 
                        prime = 0;
                        break;
                    }
                }
                if (prime) {
                    printf("%d is a prime number.\n", num);
                } else {
                    printf("%d is not a prime number.\n", num);
                }
            }
            break;

        default:
            printf("Invalid choice. Please choose 1 or 2.\n");
    }

    return 0;
}
