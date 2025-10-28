#include <stdio.h>

int main() {
    int arr[100], n, i, element, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    
    printf("Enter the element to delete: ");
    scanf("%d", &element);
    pos = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--; 
        printf("%d has been removed.\n", element);
    } else {
        printf("%d is not in the array.\n", element);
    }

   
    printf("Array after deletion: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element: ");
    scanf("%d", &pos);
    if (pos >= 0 && pos <= n) {
        for (i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = element;
        n++;
        printf("%d has been inserted at position %d.\n", element, pos);
    } else {
        printf("Invalid position.\n");
    }

    printf("Final array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
  return 0;
}

    