#include <stdio.h>
int main()
{
    int size = 0, sum = 0, min, max, choice;
    int arr[size];
    
    printf("\n.Menu:\n");
    printf("1. Read Array\n");
    printf("2. Print Array\n");
    printf("3.Print Addition of Array Elements\n");
    printf("4. Find Minimum Number from Array\n");
    printf("5. Search an Element in Array\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter the size of the array: ");
            scanf("%d", &size);
            printf(" enter %d elements:\n", size);
            for(int i = 0; i < size; i++){
                printf("element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            break;

        case 2:
        printf("Enter the size of the array: ");
            scanf("%d", &size);
            printf(" enter %d elements:\n", size);
            for(int i = 0; i < size; i++){
                printf("element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            printf("You entered:\n");
            for(int i = 0; i < size; i++){
                printf("element %d: %d\n", i + 1, arr[i]);
            }
            break;

        case 3:
        printf("Enter the size of the array: ");
            scanf("%d", &size);
            printf(" enter %d elements:\n", size);
            for(int i = 0; i < size; i++){
                printf("element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            sum = 0;
            for (int i = 0; i < size; i++){
                sum = sum + arr[i];
            }
            printf("The sum of array elements is : %d\n", sum);
            break;

        case 4:
         printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum value: %d\n", min);
    break;

        case 5:
        printf("Enter the size of the array: ");
            scanf("%d", &size);
            printf(" enter %d elements:\n", size);
            for(int i = 0; i < size; i++){
                printf("element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            {
                int search = 0, found = 0;
                printf("Enter the element to search: ");
                scanf("%d", &search);
                for(int i = 0; i < size; i++) {
                    if(arr[i] == search) {
                        printf("Element found at index %d (position %d)\n", i, i + 1);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Element not found in the array.\n");
                }
            }
            break;
        
        case 6:
            printf("Exiting program...\n");
            return 0;
    }
    return 0;
}
