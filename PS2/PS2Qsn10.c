#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25

// void populateArray(int *arr, int arrSize);
void populateArray2(int *arr, int aSz);
void displayArray(int *arr, int aSz);
void countPosNegVal(int *arr, int arrSize, int *pos, int *neg, int *zero);
void arrangeAlternateSign(int *arr, int *arrSize);
void segregateArrays(int *arr, int arrSize, int *posArr, int *negArr, int *zeroArr);
void mergeArrays(int *posArr, int *pos, int *negArr, int neg, int *zeroArr, int zero);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSize;
    printf("\nEnter No of elements in array : ");
    scanf("%d", &arrSize);
    int arr[arrSize];
    populateArray2(arr, arrSize);
    printf("\n");
    printf("\nThe Array elements are :   ");
    displayArray(arr, arrSize);
    printf("\n");
    arrangeAlternateSign(arr, &arrSize);
    printf("\n");
    printf("\nThe Array elements alternatively arranged :   ");
    displayArray(arr, arrSize);
    printf("\n");
}

void arrangeAlternateSign(int *arr, int *arrSize)
{
    int theSize = *arrSize;
    int pos = 0, neg = 0, zero = 0;
    countPosNegVal(arr, *arrSize, &pos, &neg, &zero);
    int posArr[pos], negArr[neg], zeroArr[zero];
    segregateArrays(arr, *arrSize, posArr, negArr, zeroArr);
    printf("\n");
    printf("\n");
    printf("\n");
    mergeArrays(posArr, &pos, negArr, neg, zeroArr, zero);
    for (int i = 0; i < theSize; i++)
    {
        *(arr + i) = *(posArr + i);
    }
    *arrSize = pos;
}

void segregateArrays(int *arr, int arrSize, int *posArr, int *negArr, int *zeroArr)
{
    int p = 0, n = 0, z = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (*(arr + i) == 0)
        {
            *(zeroArr + z) = *(arr + i);
            z++;
        }
        else if (*(arr + i) > 0)
        {
            *(posArr + p) = *(arr + i);
            p++;
        }
        else
        {
            *(negArr + n) = *(arr + i);
            n++;
        }
    }
}

void countPosNegVal(int *arr, int arrSize, int *pos, int *neg, int *zero)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (*(arr + i) == 0)
        {
            (*zero)++;
        }
        else if (*(arr + i) > 0)
        {
            (*pos)++;
        }
        else
        {
            (*neg)++;
        }
    }
}

void mergeArrays(int *posArr, int *pos, int *negArr, int neg, int *zeroArr, int zero)
{
    int theSz1 = *pos;
    int theSz2 = neg;
    int theSz3 = zero;
    int newArr[theSz1 + theSz2 + theSz3], newIndx = 0;
    int posIndx = 0, negIndx = 0, zeroIndx = 0;
    for (posIndx = 0, negIndx = 0; posIndx < theSz1 && negIndx < theSz2;)
    {
        *(newArr + newIndx) = *(posArr + posIndx);
        *(newArr + newIndx + 1) = *(negArr + negIndx);
        posIndx++;
        negIndx++;
        newIndx += 2;
    }

    for (int i = posIndx; i < theSz1; i++)
    {
        *(newArr + newIndx) = *(posArr + i);
        newIndx++;
    }

    for (int j = negIndx; j < theSz2; j++)
    {
        *(newArr + newIndx) = *(negArr + j);
        newIndx++;
    }
    for (int j = zeroIndx; j < theSz3; j++)
    {
        *(newArr + newIndx) = *(zeroArr + j);
        newIndx++;
    }
    for (int i = 0; i < newIndx; i++)
    {
        *(posArr + i) = *(newArr + i);
    }
    *pos = newIndx;
}
/*
void populateArray(int *arr, int arrSize)
{
    printf("\nEnter array elements : \n");
    for (int i = 0; i < arrSize; i++)
    {
        scanf("%d", (arr + i));
    }
}
*/
void populateArray2(int *arr, int aSz)
{
    int theSize = aSz;
    int theVal = 0;
    for (int i = 0; i < theSize; i++)
    {
        theVal = rand() % MAXNUM; 
        theVal++;
        int pos = rand() % 2; 
        if (0 == pos)
        {
            theVal *= -1;
        }
        *(arr + i) = theVal;
    }
}

void displayArray(int *arr, int aSz)
{
    int theSize = aSz;
    for (int i = 0; i < theSize; i++)
    {
        printf("%4d\t", *(arr + i));
    }
}
