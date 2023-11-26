#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 100
// #define MAXSIZE 20
#define MAXROWS 5
#define MAXCOLS 8
// Windows: Shift + Alt + F - for formatting

void populateArrayRandom(int aRows, int aCols, int arr[][aCols]);
void findLargestEleInEachRow(int aRows, int aCols, int arr[][aCols]);
void printArray(int aRows, int aCols, int arr[][aCols]);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrRows, arrCols;
    arrRows = MAXROWS;
    arrCols = MAXCOLS;
    int arr[arrRows][arrCols];   
    populateArrayRandom(arrRows, arrCols, arr);
    printf("\nArray elements of Matrix[%d X %d]: \n", arrRows, arrCols);
    printArray(arrRows, arrCols, arr);
    printf("\n");
    findLargestEleInEachRow(arrRows, arrCols, arr);
     printf("\n");
    return 0;
}

void findLargestEleInEachRow(int aRows, int aCols, int arr[][aCols])
{
    int theRows = aRows;
    int theCols = aCols;
    for (int i = 0; i < theRows; i++)
    {
        int theRowMax = arr[i][0];
        int maxPosnJ = 0;
        for (int j = 1; j < theCols; j++)
        {
            if (theRowMax < arr[i][j])
            {
                theRowMax = arr[i][j];
                maxPosnJ = j;                
            }
            if(j == theCols-1)
            printf("\nRow No : %d  Row Max value : %d at Coln No : %d", (i+1), theRowMax, (maxPosnJ +1));
        }
    }
}

void populateArrayRandom(int aRows, int aCols, int arr[][aCols])
{
    int theRows = aRows;
    int theCols = aCols;
    int theVal = 0;
    for (int i = 0; i < theRows; i++)
    {
        for (int j = 0; j < theCols; j++)
        {
            theVal = rand() % MAXNUM + 1;
            //  *(*(arr + i) + j) = theVal;
            //  printf("\nArray elements : %d", *(*(arr + i) + j));
            arr[i][j] = theVal;
            // printf("\nArray elements : %d", arr[i][j]);
        }
    }
}

// void printArray(int aRows, int aCols, int *(*arr))
void printArray(int aRows, int aCols, int arr[][aCols])
{
    int theRows = aRows;
    int theCols = aCols;
    for (int i = 0; i < theRows; i++)
    {
        for (int j = 0; j < theCols; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}


/*

void assign(int** arr, int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = i + j;
        }
    }
 for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}
*/

void populateArray(int arr[], int arrSize)
{
    printf("\nEnter array elements : \n");
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
}
