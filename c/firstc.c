#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Addition of two matrices");
        printf("2. Multiplication of two matrices");
        printf("3. Transpose of matrix");
        printf("1. Exit");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
       switch(choice){
              case 1:{
                      int rows, cols;
                      printf("Enter the no. of rows and columns of the matrices: ");
                      scanf("%d, %d", &rows, &cols);
                      
                      int matrix1 [rows][cols], matrix2 [rows][cols], result[rows][cols];
                      
                      printf("Enter elements of First Matrix:\n");
                      for(int i = 0; i < rows; i++)
                      {
                          for(int j = 0; j < cols; j++)
                          {
                              printf(" Element [%d}\][%d]", i + 1, j + 1);
                              scanf("%d", &matr)
                          }
                      }
                      
              }
       }
    }
    printf("Hello world!\n");
    return 0;
}