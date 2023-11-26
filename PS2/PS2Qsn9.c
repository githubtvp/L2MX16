#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25

void populateArray(int *arr, int aSz);
void displayArray(int *arr, int aSz);
void removeDuplicatesInArray(int *arr, int *aSz);
void shiftLeftArrElements(int *arr, int arrSz, int aStPosn);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSize;
    printf("\nEnter No of elements in array : ");
    scanf("%d", &arrSize);
    int arr[arrSize];

    populateArray(arr, arrSize);
    printf("\n");
    printf("\nThe Array elements are :   ");
    displayArray(arr, arrSize);
    removeDuplicatesInArray(arr, &arrSize);
    printf("\nThe Array elements after removal of duplicates :   ");
    displayArray(arr, arrSize);
    printf("\n");
}

void populateArray(int *arr, int aSz)
{
    int theSize = aSz;
    int theVal = 0;
    for (int i = 0; i < theSize; i++)
    {
        theVal = rand() % MAXNUM;
        theVal++;
        *(arr + i) = theVal;
    }
}

void displayArray(int *arr, int aSz)
{
    int theSize = aSz;
    for (int i = 0; i < theSize; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

void removeDuplicatesInArray(int *arr, int *aSz)
{
    int theSize = *aSz;
    int refPosn = 0;
    bool found = false;
    for (int i = 0; i < theSize - 1; i++)
    {
        for (int j = i + 1; j < theSize; j++)
        {
            if (*(arr + i) == *(arr + j))
            {
                found = true;
                shiftLeftArrElements(arr, theSize, j);
                theSize--;
                j--;
            }
        }
    }
    *aSz = theSize;
    if (!found)
    {
        printf("\nNo duplicates were found in the Array\n");
    }
    else
    {
        printf("\nAll duplicates removed from the Array\n");
    }
}

void shiftLeftArrElements(int *arr, int arrSz, int aStPosn)
{
    int theArrSize = arrSz;
    int theStartIndx = aStPosn;
    int theStIndx = theStartIndx;
    for (int i = theStIndx + 1; i < theArrSize; i++)
    {
        *(arr + theStIndx) = *(arr + i);
        theStIndx++;
    }
}
