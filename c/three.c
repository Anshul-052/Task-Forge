#include<stdio.h>
int main()
{
    int num;
    printf("enter the no.:");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("it is even");
    }
    else
    {
      printf("it is odd");
    }
    
    return 0;
    

}