#include<stdio.h>
#include<stdlib.h>

void staticArrayInputOutput();
void dynamicArrayInputOutput();

int main(){
    int choice;

    do{
        printf("\nMenu;\n");
        printf("1. Accept and print array elements (static allocation).\n");
        printf("2. Accept and print array elements (dynamic allocation).\n");
        printf("3. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice){
        case 1:
            staticArrayInputOutput();
            break;
        case 2:
            dynamicArrayInputOutput();
            break;
        case 3:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
    }while (choice != 3);
    return 0;
}

void staticArrayInputOutput(){
    int n, i;
    int arr[100];
    int *ptr = arr;

    printf("\nEnter the number of elements (max 100): ");
    scanf("%d", &n);
    if (n > 100){
        printf("Error: Number of element exceeds array size!\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++){
        printf("Element %d: %d\n", i + 1, *(ptr + i));
    }
}

void dynamicArrayInputOutput(){
    int n, i;
    int *arr;

    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL){
        printf("memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are:\n", n);
    for (i = 0; i < n; i++){
        printf("Element %d: %d\n", i + 1, arr[i]);
    }
    

  free(arr);
}