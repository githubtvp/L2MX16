#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
// Windows: Shift + Alt + F - for formatting

/*
1. Name of the 1-D array = 'arr' reps address of the first
element in the 1-D array
1(a)  and arr + 1 will rep address of the 2nd element
2. Name of the 2-D array 'arr' reps address of the first
row in the 2-D array
2(a) and arr + 1 will rep address of the second row in the 2-D array

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
#define MAXNUM 10

void populate2DArray(int arrSize, int (*arr)[arrSize]);
void populate2DUpperTriangularMxArray(int arrSize, int (*arr)[arrSize], bool upper);
void printSumsOfTriangles(int arrSize, int (*arr)[arrSize], bool upper);

void printArray(int arrSize, int (*arr)[arrSize]);
void printSumOfDiagnolElements(int arrSize, int (*arr)[arrSize]);

int main()
{
    int arrSize;
    time_t theSeed;
    /* define the random number generator */
    srand((unsigned)time(&theSeed)); // pass the srand() parameter
    arrSize = ARRSIZE;
    int arr[arrSize][arrSize];
    populate2DArray(arrSize, arr);
    printf("\nThe array elements are :  \n");
    printArray(arrSize, arr);
    printSumOfDiagnolElements(arrSize, arr);
    printf("\n");
    bool upper = true; // false;
    populate2DUpperTriangularMxArray(arrSize, arr, upper);
    printf("\nThe array elements of Upper Triangular Matrix are :  \n");
    printArray(arrSize, arr);
    printSumsOfTriangles(arrSize, arr, upper);
    printf("\n");
    upper = false;
    populate2DUpperTriangularMxArray(arrSize, arr, upper);
    printf("\nThe array elements of Lower Triangular Matrix are :  \n");
    printArray(arrSize, arr);
    printSumsOfTriangles(arrSize, arr, upper);
    printf("\n\n");
    return 0;
}

void printSumsOfTriangles(int arrSize, int (*arr)[arrSize], bool upper)
{
    int nRows = arrSize;
    int mCols = arrSize;
    int sum = 0;
    int startJ = 0, endJ = 0;
    for (int i = 0; i < nRows; i++)
    {
        if (upper)
        {
            startJ = i;
            endJ = mCols - 1;
        }
        else
        {
            startJ = 0;
            endJ = i;
        }
        for (int j = startJ; j <= endJ; j++)
        {
            sum += *(*(arr + i) + j);
        }
    }
    printf("\nThe Sum of elements of %s Triangular Matrix is :  %d", (upper ? "Upper" : "Lower"), sum);
}

void populate2DUpperTriangularMxArray(int arrSize, int (*arr)[arrSize], bool upper)
{
    int nRows = arrSize;
    int mCols = arrSize;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            if (upper ? j < i : j > i)
            {
                *(*(arr + i) + j) = 0;
            }
            else
            {
                int aVal;
                aVal = rand() % MAXNUM;
                aVal++;
                *(*(arr + i) + j) = aVal; // rand() % MAXNUM;
            }
        }
    }
}

void printSumOfDiagnolElements(int arrSize, int (*arr)[arrSize])
{
    int nRows = arrSize;
    int mCols = arrSize;
    int sum = 0;
    printf("\nThe Major Diagnol elements are :  ");
    for (int i = 0, j = 0; i < nRows; i++, j++)
    {
        sum += *(*(arr + i) + j);
        printf("%d\t", *(*(arr + i) + j));
    }
    printf("\nThe Sum of Major Diagnol elements is : %d", sum);
    sum = 0;
    printf("\n\nThe Minor Diagnol elements are :  ");
    for (int i = nRows - 1, j = 0; i >= 0; i--, j++)
    {
        sum += *(*(arr + i) + j);
        printf("%d\t", *(*(arr + i) + j));
    }
    printf("\nThe Sum of Minor Diagnol elements is : %d", sum);
}

void populate2DArray(int arrSize, int (*arr)[arrSize])
{
    int nRows = arrSize;
    int mCols = arrSize;
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < mCols; j++)
        {
            *(*(arr + i) + j) = rand() % MAXNUM;
            //  *(*(arr + i) + j) = i + j + 1; // *(arr+ i) gives the address of the (i,0) element,
            // as a[i] in a 2 D array is the address of the i row
            // also same as
            //  *( arr[i] + j) = i + j;  - 'coz *(arr+i) = a[i]
        }
    }
}

void printArray(int arrSize, int (*arr)[arrSize])
{
    int nRows = arrSize;
    int mCols = arrSize;
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
