#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
// Windows: Shift + Alt + F - for formatting

/*
1. Name of the 1-D array reps address of the first
element in the 1-D array
2. Name of the 2-D array reps address of the first
row in the 2-D array

In 2 D array following apply
int a[3][3] = {6, 2, 5, 0, 1, 3, 4, 9, 8};
int *p;
p = a; // it is Valid in 1 D array but InValid in 2 D array, 'coz
in 2 D array 'a' is a pointer and it represents the entire 0th row elements and
not just [0][0] element
similarly a[1] reps entire 1st row elements

p = &a[0][0] - Valid
p = a[0] -Valid 'coz a[0] is a 1 D array and so its name represents the address of
its 1st element in 1 D array
P = a[0][0] - InValid

also
a = a[0] = &a[0] = &a[0][0] = &a = *a - base address of 0th row array
a+1 = &a[1] - base address of 1st row array
*(a+1) = a[1] = &a[1][0] - base address of 1st row array
*(a+1) + 2 = address of 1st row 2nd coln element = &a[1][2](not the value at that posn)
*( *(a+1) + 2 ) =  value of element at a[1][2] = {3}
therefore
*( *(a+i) + j ) = a[i][j] is the general form of any element
in 2 D array pointer notation
also
*( *(a+i) + j ) = *(a[i] + j) 'coz *(a+i) = a[i] in 2D array
i.e. address of ith row, 0th element


*/

#define ARRSIZE 5
#define MAXNUM 5
#define MAXROWS 6
#define MAXCOLS 5

void populate2DArray(int rows, int cols, int (*arr)[cols]);
void insertSingleZero(int rows, int cols, int (*arr)[cols]);
void insertZeroInEntireRowColn(int rows, int cols, int (*arr)[cols]);
void makeItZeros(int rows, int cols, int (*arr)[cols], int aRow, int aCol);
void printArray(int rows, int cols, int (*arr)[cols]);

int main()
{
  //  int arrSize;
 //   time_t theSeed;
    /* define the random number generator */
 //   srand((unsigned)time(&theSeed)); // pass the srand() parameter
  //  arrSize = ARRSIZE;
    int nRows = MAXROWS, mCols = MAXCOLS;
    printf("\nEnter number of Rows in the Matrix : ");
    scanf("%d", &nRows);
    printf("\nEnter number of Columns in the Matrix : ");
    scanf("%d", &mCols);
    int arr[nRows][mCols];
    populate2DArray(nRows, mCols, arr);
    printf("\nThe Array elements with no zero :  \n");
    printArray(nRows, mCols, arr);
 /*   printf("\nThe Array elements with a Single zero :  \n");
    insertSingleZero(nRows, mCols, arr);
    printArray(nRows, mCols, arr);
    printf("\nThe New array with modified values :  \n");
    insertZeroInEntireRowColn(nRows, mCols, arr);
    printArray(nRows, mCols, arr);
 */   printf("\n\n");

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
            scanf("%d",  (*(arr + i) + j) );   
        //    *(*(arr + i) + j) = aVal;
            //  *(*(arr + i) + j) = i + j + 1; // *(arr+ i) gives the address of the (i,0) element,
            // as a[i] in a 2 D array is the address of the i row
            // also same as
            //  *( arr[i] + j) = i + j;  - 'coz *(arr+i) = a[i]
        }
    }
}

void insertSingleZero(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    int aVal, theRowNo, theColNo;
    do
    {
        aVal = rand() % MAXNUM;
    } while (aVal >= nRows);
    theRowNo = aVal;
    do
    {
        aVal = rand() % MAXNUM;
    } while (aVal >= mCols);
    theColNo = aVal;
    *(*(arr + theRowNo) + theColNo) = 0;
    printf("\nModified to 0 the element at M(x , y) : M(%d , %d) \n", theRowNo + 1, theColNo + 1);
}

void insertZeroInEntireRowColn(int rows, int cols, int (*arr)[cols])
{
    int nRows = rows;
    int mCols = cols;
    int aVal, theRowNo, theColNo;
   // bool found = false;
    int zeroCnt = 0;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            if (0 == *(*(arr + i) + j))
            {
               // found = true;
                theRowNo = i;
                theColNo = j;
                zeroCnt+=1;
            }
        }
    }
    if (0==zeroCnt)
    {
        printf("\n No 0 Value element found in Matrix! ");
    }
    else if(zeroCnt > 1)
    {
        printf("\n More than one No 0 Value element found in Matrix! ");
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
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            //  printf("%4d", *( *(arr + i) + j) );
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n\n");
    }
}
