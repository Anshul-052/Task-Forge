#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int j = 0, len, start, end, temp, choice;
    int flag = 0;
    int i = 0;

    while (1) {
        printf("\nMenu: \n");
        printf("1. Print string length\n");
        printf("2. Print string in reverse order\n");
        printf("3. Copy given string into other string and print both strings\n");
        printf("4. Accept two strings from user and compare both. Print if they are equal.\n");
        printf("5. Accept two strings from user and print their concatenated string\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the integer input

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strlen(str1) - 1] = '\0'; // Remove newline character

                len = 0;
                while (str1[len] != '\0') {
                    len++;
                }
                printf("Length of the string: %d\n", len);
                break;

            case 2:
                printf("Enter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strlen(str1) - 1] = '\0'; // Remove newline character

                len = 0;
                while (str1[len] != '\0') {
                    len++;
                }

                start = 0;
                end = len - 1;
                while (start < end) {
                    temp = str1[start];
                    str1[start] = str1[end];
                    str1[end] = temp;
                    start++;
                    end--;
                }
                printf("Reversed string: %s\n", str1);
                break;

            case 3:
                printf("Enter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strlen(str1) - 1] = '\0'; // Remove newline character
                printf("Enter the destination string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strlen(str2) - 1] = '\0'; // Remove newline character

                i = 0;
                while (str1[i] != '\0') {
                    str2[i] = str1[i];
                    i++;
                }
                str2[i] = '\0';
                printf("Source string: %s\n", str1);
                printf("Copied string: %s\n", str2);
                break;

            case 4:
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strlen(str1) - 1] = '\0'; // Remove newline character

                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strlen(str2) - 1] = '\0'; // Remove newline character

                i = 0;
                flag = 0;
                while (str1[i] != '\0' || str2[i] != '\0') {
                    if (str1[i] != str2[i]) {
                        flag = 1;
                        break;
                    }
                    i++;
                }

                if (flag == 0) {
                    printf("Strings are equal.\n");
                } else {
                    if (str1[i] == '\0' && str2[i] != '\0') {
                        printf("First string is smaller.\n");
                    } else if (str1[i] != '\0' && str2[i] == '\0') {
                        printf("First string is greater.\n");
                    } else {
                        printf("Strings are not equal.\n");
                    }
                }
                break;

            case 5:
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strlen(str1) - 1] = '\0'; // Remove newline character
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strlen(str2) - 1] = '\0'; // Remove newline character

                i = 0;
                while (str1[i] != '\0') {
                    i++;
                }

                j = 0; // Reset j for concatenation
                while (str2[j] != '\0') {
                    str1[i] = str2[j];
                    i++;
                    j++;
                }

                str1[i] = '\0';
                printf("Concatenated string: %s\n", str1);
                break;
                
                     case 6:
                printf("Exiting the program.\n");
                return 0;
default: 
printf("Invalid choice. Please try again.\n"); } 
        }       
}

                