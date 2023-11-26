#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25

void populateArray(int *arr, int aSz);
void displayArray(int *arr, int aSz);
void sortTheArray(int *arr, int aSz);
void mergeSortedArrays(int *arr1, int *aSz1, int *arr2, int aSz2);
void swap(int *arr, int posn1, int posn2);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSize1, arrSize2;
    printf("\nEnter No of elements in 1st array : ");
    scanf("%d", &arrSize1);
    printf("\nEnter No of elements in 2nd array : ");
    scanf("%d", &arrSize2);
    int arr1[arrSize1];
    int arr2[arrSize2];

    populateArray(arr1, arrSize1);
    printf("\n");
    printf("\nThe Array 1 elements are :   ");
    displayArray(arr1, arrSize1);
    sortTheArray(arr1, arrSize1);
    printf("\nSorted Array 1 elements are :   ");
    displayArray(arr1, arrSize1);

    populateArray(arr2, arrSize2);
    printf("\n");
    printf("\nThe Array 2 elements are :   ");
    displayArray(arr2, arrSize2);
    sortTheArray(arr2, arrSize2);
    printf("\nSorted Array 2 elements are :   ");
    displayArray(arr2, arrSize2);
    mergeSortedArrays(arr1, &arrSize1, arr2, arrSize2);
    printf("\n");
    printf("\nMerged Sorted Array elements are :   ");

    displayArray(arr1, arrSize1);
}

void mergeSortedArrays(int *arr1, int *aSz1, int *arr2, int aSz2)
{
    int theSz1 = *aSz1;
    int theSz2 = aSz2;
    int newArr[theSz1 + theSz2], newIndx = 0;
    int arr1Indx = 0, arr2Indx = 0;
    for (arr1Indx = 0, arr2Indx = 0; arr1Indx < theSz1 && arr2Indx < theSz2;)
    {
        if (*(arr1 + arr1Indx) <= *(arr2 + arr2Indx))
        {
            *(newArr + newIndx) = *(arr1 + arr1Indx);
            arr1Indx++;
        }
        else
        {
            *(newArr + newIndx) = *(arr2 + arr2Indx);
            arr2Indx++;
        }
        newIndx++;
    }
    for (int i = arr1Indx; i < theSz1; i++)
    {
        *(newArr + newIndx) = *(arr1 + i);
        newIndx++;
    }

    for (int j = arr2Indx; j < theSz2; j++)
    {
        *(newArr + newIndx) = *(arr2 + j);
        newIndx++;
    }

    printf("\n");
    for (int i = 0; i < newIndx; i++)
    {
        *(arr1 + i) = *(newArr + i);
    }
    *aSz1 = newIndx;
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

void sortTheArray(int *arr, int aSz)
{
    int theSize = aSz;
    int refPosn = 0;
    for (int i = 0; i < theSize - 1; i++)
    {
        refPosn = i;
        for (int j = i + 1; j < theSize; j++)
        {
            if (*(arr + refPosn) > *(arr + j))
            {
                refPosn = j;
            }
        }
        if (refPosn != i)
        {
            swap(arr, i, refPosn);
        }
    }
}

void swap(int *arr, int posn1, int posn2)
{
    int thePosn1, thePosn2, temp;
    temp = *(arr + posn1);
    *(arr + posn1) = *(arr + posn2);
    *(arr + posn2) = temp;
}
