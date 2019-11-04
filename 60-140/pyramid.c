#include <stdio.h>

int main()
{
    int i, space, rows, n, k = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    rows = n / 2 + 1;

    for(i = 0; i < rows; i++)
    { 
        for(space = 0; space < rows - i; space++)
        {
           printf("  ");
        }

        while(k != 2 * (i + 1) - 1)
        {
           printf("* ");
           k++;
        }

        k = 0;
        printf("\n");
    }

    return 0;
}