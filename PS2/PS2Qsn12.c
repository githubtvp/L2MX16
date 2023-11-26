#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25

void populateArray(int *arr, int aSz);
void displayArray(int *arr, int aSz);
void sortTheArray(int *arr, int aSz);
void swap(int *arr, int posn1, int posn2);
bool elementFoundInArray(int arr[], int aSz, int aVal);
int findMinOf3(int a1, int a2, int a3, int *arrSz4);
void checkEachArr(int arr1[], int aSz1, int arr2[], int aSz2, int arr3[], int aSz3, int arr4[], int *aSz4);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSize1, arrSize2, arrSize3, arrSize4;
    printf("\nEnter No of elements in 1st array : ");
    scanf("%d", &arrSize1);
    printf("\nEnter No of elements in 2nd array : ");
    scanf("%d", &arrSize2);
    printf("\nEnter No of elements in 3rd array : ");
    scanf("%d", &arrSize3);
    printf("\nGenerating the three arrays with random numbers.... ");
    int arr1[arrSize1];
    int arr2[arrSize2];
    int arr3[arrSize3];
    // int arr1[5] = {2,4,5,6, 9};
    //   int arr2[7] = {5,3,2,8, 3, 7, 0};
    //  int arr3[9] = {5,1, 6, 3, 2, 8, 9, 0, 4};
    populateArray(arr1, arrSize1);
    printf("\n");
    sortTheArray(arr1, arrSize1);
    printf("\nSorted Array 1 elements are :   ");
    displayArray(arr1, arrSize1);
    populateArray(arr2, arrSize2);
    printf("\n");
    sortTheArray(arr2, arrSize2);
    printf("\nSorted Array 2 elements are :   ");
    displayArray(arr2, arrSize2);
    printf("\n");
    populateArray(arr3, arrSize3);
    printf("\n");
    sortTheArray(arr3, arrSize3);
    printf("\nSorted Array 3 elements are :   ");
    displayArray(arr3, arrSize3);
    printf("\n");

    int minSize = findMinOf3(arrSize1, arrSize2, arrSize3, &arrSize4);
    int arr4[arrSize4];
    switch (minSize)
    {
    case 1:
        checkEachArr(arr1, arrSize1, arr2, arrSize2, arr3, arrSize3, arr4, &arrSize4);
        break;
    case 2:
        checkEachArr(arr2, arrSize2, arr1, arrSize1, arr3, arrSize3, arr4, &arrSize4);
        break;
    case 3:
        checkEachArr(arr3, arrSize3, arr2, arrSize2, arr1, arrSize1, arr4, &arrSize4);
        break;
    default:
        break;
    }
    printf("\n");
    if (arrSize4)
    {
        printf("\nThe Common elements in all 3 array are :   ");
        displayArray(arr4, arrSize4);
    }
    printf("\n");
    return 0;
}

void checkEachArr(int arr1[], int aSz1, int arr2[], int aSz2, int arr3[], int aSz3, int arr4[], int *aSz4)
{
    int theSize1 = aSz1;
    bool found = false;
    int comCnt = 0;
    int indx4 = 0;
    for (int i = 0; i < theSize1; i++)
    {
        int theCurEl = arr1[i];
        if (elementFoundInArray(arr2, aSz2, theCurEl) && elementFoundInArray(arr3, aSz3, theCurEl))
        {
            found = true;
            comCnt++;
            if (!elementFoundInArray(arr4, *aSz4, theCurEl))
            {
                arr4[indx4] = theCurEl;
                indx4++;
                *aSz4 = indx4;
            }
        }
    }
    if (!found)
        printf("\nZero Common elements: \n");
    if (comCnt)
        printf("\nNo of Common elements are : %d\n", comCnt);
}

int findMinOf3(int a1, int a2, int a3, int *arrSz4)
{
    if (a1 <= a2) // a1 <= a2 => a1 and a3
    {
        if (a1 <= a3) // a1 < a3
        {
            *arrSz4 = a1;
            return 1;
        }
        else
        {
            *arrSz4 = a3;
            return 3; // else a3 < a1
        }
    }
    else // a2 < a1 => a2 and a3
    {
        if (a2 <= a3) // a2 < a3
        {
            *arrSz4 = a2;
            return 2;
        }
        {
            *arrSz4 = a3;
            return 3; // else a3 < a2
        }
    }
}

void populateArray(int *arr, int aSz)
{
    int theSize = aSz;
    int theVal = 0;
    for (int i = 0; i < theSize; i++)
    {
        theVal = rand() % MAXNUM; /* code */
        theVal++;
        *(arr + i) = theVal;
    }
}

bool elementFoundInArray(int arr[], int aSz, int aVal)
{
    int theSize = aSz;
    int theVal = aVal;
    bool found = false;
    for (int i = 0; i < theSize && !found; i++)
    {
        if (theVal == arr[i])
        {
            found = true;
        }
    }
    return found;
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
                //   printf("\n Ref posn , j Val : %d,   %d", refPosn, j);
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
