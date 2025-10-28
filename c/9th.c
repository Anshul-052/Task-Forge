#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int stringLength(const char *str)
    {
      const char *ptr = str;
      int length = 0;

       while (*ptr != '\0'){
        length++;
        ptr++;
    }
        return length;
    }


void stringCopy (char *destination, const char *source){
    while (*source != '\0'){
        *destination = *source;   
        source++;
        destination++;  
    }
    *destination = '\0';
}

int main () {
    char str[100], source[100], destination[100];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Find length of a string\n");
        printf("2. Copy one string into another\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                printf("Enter the source string: ");
                fgets(str, sizeof(str), stdin);
                str[stringLength(str) - 1] = '\0';
                printf("The length of the string is: %d\n", stringLength(str));
                break;
            case 2:
                printf("Enter the source string: ");
                fgets(source, sizeof (source), stdin);
                source[stringLength(source) - 1] = '\0';
                stringCopy(destination, source);
                printf("Source string: %s\n", source);
                printf("Copied string: %s\n", destination);
                break;
            case 3:
                printf("Exinting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }          
    }while(choice != 3);
    return 0;
}