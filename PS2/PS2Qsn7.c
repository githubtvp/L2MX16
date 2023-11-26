#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
// Windows: Shift + Alt + F - for formatting

#define ARRSIZE 5
#define MAXNUM 5
#define MAXROWS 6
#define MAXCOLS 5

void populate2DArray(int rows, int cols, int (*arr)[cols]);
void checkForZeros(int rows, int cols, int (*arr)[cols];);
void makeItZeros(int rows, int cols, int (*arr)[cols], int aRow, int aCol);
void printArray(int rows, int cols, int (*arr)[cols]);

int main()
{
    int nRows, mCols;
    printf("\nEnter number of Rows in the Matrix : ");
    scanf("%d", &nRows);
    printf("\nEnter number of Columns in the Matrix : ");
    scanf("%d", &mCols);
    int arr[nRows][mCols];
    populate2DArray(nRows, mCols, arr);
    printf("\nThe Array elements entered are :  \n");
    printf("\n");
    printArray(nRows, mCols, arr);
    printf("\n");
    checkForZeros(nRows, mCols, arr);
    printf("\nThe Array elements entered are :  \n");
    printArray(nRows, mCols, arr);
    printf("\n\n");

    return 0;
}

void populate2DArray(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    printf("\nEnter array elements row wise : \n");
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            scanf("%d", (*(arr + i) + j));
            //  *(*(arr + i) + j) = i + j + 1; // *(arr+ i) gives the address of the (i,0) element,
            // as a[i] in a 2 D array is the address of the i row
            // also same as
            //  *( arr[i] + j) = i + j;  - 'coz *(arr+i) = a[i]
        }
    }
}

void checkForZeros(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    int aVal, theRowNo, theColNo;
    int zeroCnt = 0;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            if (0 == *(*(arr + i) + j))
            {
                theRowNo = i;
                theColNo = j;
                zeroCnt += 1;
            }
        }
    }
    if (0 == zeroCnt)
    {
        printf("\nNo 0 Value element found in Matrix! \n");
    }
    else if (zeroCnt > 1)
    {
        printf("\nMore than one 0 Value element found in Matrix! \n");
    }
    else
    {
        printf("\nFound a single 0 value element at M(x , y) : M(%d , %d) \n", theRowNo + 1, theColNo + 1);
        makeItZeros(nRows, mCols, arr, theRowNo, theColNo);
    }
}

void makeItZeros(int rows, int cols, int (*arr)[cols], int aRow, int aCol)
{
    int nRows = rows;
    int mCols = cols;
    int theRowNo = aRow, theColNo = aCol;
    int i = theRowNo;
    printf("\nModified to 0 the entire Row No :%d \n", theRowNo + 1);
    for (int j = 0; j < mCols; j++)
    {
        *(*(arr + i) + j) = 0;
    }
    int j = theColNo;
    printf("\nModified to 0 the entire Col No :%d \n", theColNo + 1);
    for (int i = 0; i < nRows; i++)
    {
        *(*(arr + i) + j) = 0;
    }
}

void printArray(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    printf("\n");
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n\n");
    }
}
