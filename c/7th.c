#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Addition of two matrices\n");
        printf("2. Multiplication of two matrices\n");
        printf("3. Transpose of matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int rows, cols;
            printf("Enter the number of rows and columns of the matrices: ");
            scanf("%d %d", &rows, &cols);

            int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

            printf("Enter elements of First Matrix:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf(" Element [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &matrix1[i][j]);
                }
            }
            printf("Enter elements of Second Matrix:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf(" Element [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &matrix2[i][j]);
                }
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            printf("Resultant matrix after addition:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
        break;
        
        case 2: {
            int rows1, cols1, rows2, cols2;

            printf("Enter the number of rows and columns of the first matrix: ");
            scanf("%d %d", &rows1, &cols1);

            printf("Enter the number of rows and columns of the second matrix: ");
            scanf("%d %d", &rows2, &cols2);

            if (cols1 != rows2) {
                printf("Matrix multiplication is not possible.\n");
                break;
            }
            int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

            printf("Enter elements of First Matrix:\n");
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols1; j++) {
                    printf(" Element [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &matrix1[i][j]);
                }
            }
            
            printf("Enter elements of Second Matrix:\n");
            for (int i = 0; i < rows2; i++) {
                for (int j = 0; j < cols2; j++) {
                    printf(" Element [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &matrix2[i][j]);
                }
            }
            
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols2; j++) {
                    result[i][j] = 0;
                    for (int k = 0; k < cols1; k++) {
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            
            printf("Resultant matrix after multiplication:\n");
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols2; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
        }
        break;

        case 3: {
            int rows, cols;
            
            printf("Enter the number of rows and columns of the matrix: ");
            scanf("%d %d", &rows, &cols);

            int matrix[rows][cols], transpose[cols][rows];

            printf("Enter elements of the matrix:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf(" Element [%d][%d]: ", i + 1, j + 1);
                    scanf("%d", &matrix[i][j]);
                }
            }
            
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    transpose[j][i] = matrix[i][j];
                }
            }
            
            printf("Transposed matrix:\n");
            for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    printf("%d ", transpose[i][j]);
                }
                printf("\n");
            }
        }
        break;

        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}