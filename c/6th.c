#include<stdio.h>
int main()
{
    int choice, a, b, and = 0, or = 0;
    int rshift = 0, lshift = 0;

while (1) {
    printf("\n.Menu:\n");
    printf("1. Bitwise And\n");
    printf("2. Bitwise Or\n");
    printf("3. Right shift\n");
    printf("4. Left shift\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        printf("Enter first integers: ");
        scanf("%d", &a);
        printf("Enter second integers: ");
        scanf("%d", &b);

        and = a & b;
        
        printf("The bitwise and of %d & %d is %d", a, b, and);
        break;
    
    case 2:
        printf("Enter first integers: ");
        scanf("%d", &a);
        printf("Enter second integers: ");
        scanf("%d", &b);

        or = a | b;
        
        printf("The bitwise and of %d & %d is %d", a, b, or);
        break;

    case 3:
        printf("Enter first integers: ");
        scanf("%d", &a);
        printf("Enter second integers: ");
        scanf("%d", &b);

        rshift = a >> b;
        
        printf("The right shift of %d by %d is %d", a, b, rshift);
        break;
    
    case 4:
       printf("Enter first integers: ");
        scanf("%d", &a);
        printf("Enter second integers: ");
        scanf("%d", &b);

        lshift = a << b;
        
        printf("The left shift of %d by %d is %d", a, b, lshift);
        break;

    case 5:
                printf("Exiting the program.\n");
                return 0;
default: 
printf("Invalid choice. Please try again.\n"); } 
}
        }   

