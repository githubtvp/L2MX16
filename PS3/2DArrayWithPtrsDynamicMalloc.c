#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100
// #define MAXSIZE 20
#define MAXROWS 5
#define MAXCOLS 8
// Windows: Shift + Alt + F - for formatting

void assign(int **arr, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr[i][j] = i + j;
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

void process1DArray(int *arrC, int cSz)
{
    printf("\n");
    for (int j = 0; j < cSz; j++)
    {
        *(arrC + j) = 2 * j;
        printf("arrC[%d] : %3d  ", j, arrC[j]);
    }
    printf("\n");
    for (int j = 0; j < cSz; j++)
    {
        printf("%3d", arrC[j]);
    }
}

// main function
int main(void)
{
    //  int a = 5;
    //  int b = 5;
    int a; // = 5;
    int b; // = 5;
    int c;

    printf("\nEnter the no of Rows : ");
    scanf("%d", &a);
    printf("\nEnter the no of Cols : ");
    scanf("%d", &b);
    printf("\nEnter the no of elements in arrC : ");
    scanf("%d", &c);
    
    // memory allocation for 'a' rows of int ptr
    int **arr = (int **)malloc(a * sizeof(int *));//allocate memory to array of row pointers

    // memory allocation for each row ptr of 'b' int elements each
    for (int r = 0; r < a; r++)
    {
        arr[r] = (int *)malloc(b * sizeof(int));//allocate memory to each of the row pointers
    }

    assign(arr, a, b);

    int *arrC;
    arrC = malloc(c * sizeof(int));
    process1DArray(arrC, c);

    // deallocate memory
    for (int i = 0; i < a; i++)
    {
        free(arr[i]);
    }

    free(arr);

    free((int *)arrC);

    return 0;
}
