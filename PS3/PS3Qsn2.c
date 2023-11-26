#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 100
#define MAXSIZE 20
// Windows: Shift + Alt + F - for formatting

void sumOfElementsAndCountLessThan10(int arr[], int aSz, int *aSum, int *aCnt);
void createNewArrB(int arrA[], int aSz, int arrB[]);

void populateArrayRandom(int *arr, int aSz);
void populateArray(int arr[], int arrSize);
void printArray(int *arr, int aSz);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSz = MAXSIZE;
    int arrA[arrSz];
    int arrB[arrSz];
    populateArrayRandom(arrA, arrSz);
    printf("\nArray A elements : ");
    printArray(arrA, arrSz);
    printf("\n");
    int theCnt, theSum;
    sumOfElementsAndCountLessThan10(arrA, arrSz, &theSum, &theCnt);
    printf("\nSum of elements of Array : %d, and number of elements  less than 10 : %d", theSum, theCnt);
    createNewArrB(arrA, arrSz, arrB);
    printf("\n\nArray B elements : ");
    printArray(arrB, arrSz);    
    printf("\n");
    return 0;
}

void createNewArrB(int arrA[], int aSz, int arrB[])
{
    int theSz = aSz;
    int theBSum = 0;
    for (int i = 0; i < theSz; i++)
    {
        theBSum += arrA[i];
        arrB[i] = theBSum;
    }
}

void sumOfElementsAndCountLessThan10(int arr[], int aSz, int *aSum, int *aCnt)
{
    int theSz = aSz;
    int theSum = 0;
    int theCnt = 0;
    for (int i = 0; i < theSz; i++)
    {
        theSum += arr[i];
        if (arr[i] < 10)
            theCnt++;
    }
    *aSum = theSum;
    *aCnt = theCnt;
}

void copyArray(int arrOrig[], int aSz, int arrCopy[], int *aCopySz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        arrCopy[i] = arrOrig[i];
    }
    *aCopySz = theSz;
}

void populateArray(int arr[], int arrSize)
{
    printf("\nEnter array elements : \n");
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void populateArrayRandom(int *arr, int aSz)
{
    int theSize = aSz;
    int theVal = 0;
    for (int i = 0; i < theSize; i++)
    {
        theVal = rand() % MAXNUM + 1;
        *(arr + i) = theVal;
    }
}

void printArray(int *arr, int aSz)
{
    int theSize = aSz;
    for (int i = 0; i < theSize; i++)
    {
        printf("%d\t", *(arr + i));
    }
}
