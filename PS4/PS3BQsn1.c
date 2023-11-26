#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_BUF 1000
#define MAXNO 20

void populateArray(int *arr, int aSz);
void populateArrRandomNos(int *arr, int aSz);
void discardPrimeShiftLeft(int *arr, int *aSz);
void shiftLeft(int *arr, int *aSz, int aDiscIndx);
bool isPrimeNo(int aNo);

void prArray(int *arr, int aSz);

int main()
{
    srand(time(0));
    int theSz;
    printf("\nEnter the no of integer entries in array : ");
    scanf("%d", &theSz);
    int *arr = (int *)malloc(theSz * sizeof(int));
    populateArray(arr, theSz);
   // populateArrRandomNos(arr, theSz);
    prArray(arr, theSz);
    discardPrimeShiftLeft(arr, &theSz);
    printf("\nArray elements after removing prime numbers:");
    prArray(arr, theSz);
    free(arr);
    return 0;
}

void discardPrimeShiftLeft(int *arr, int *aSz)
{
    int theSz = *aSz;
    for (int i = 0; i < theSz; i++)
    {
        int theCurEl = *(arr + i);
        if (isPrimeNo(theCurEl))
        {
            shiftLeft(arr, &theSz, i);
            i--;
        }
    }
    *aSz = theSz;
}

void shiftLeft(int *arr, int *aSz, int aDiscIndx)
{
    int theSz = *aSz;
    int theDiscardIndx = aDiscIndx;
    for (int i = theDiscardIndx; i < theSz; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    theSz--;
    *aSz = theSz;
}

bool isPrimeNo(int aNo)
{
    int theNo = aNo;
    int theTestLimNo;
    bool prime = true;
    if (0 == theNo || 1 == theNo)
    {
        return !prime;
    }
    else if (2 == theNo)
    {
        return prime;
    }
    else
    {
        theTestLimNo = (int)ceil((sqrt((double)(theNo))));
        for (int i = 2; i < (theTestLimNo + 1); i++)
        {
            if (0 == theNo % i)
            {
                return !prime;
            }
        }
    }
    return prime;
}
void populateArrRandomNos(int *arr, int aSz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        int theVal = rand() % MAXNO + 1;
        *(arr + i) = theVal;
        // arr[i] = theVal;//also valid statement - works
    }
}

void populateArray(int *arr, int aSz)
{
    int theSz = aSz;
    printf("\nThe size of array : %d", theSz);
    printf("\nEnter the integer elements one by one : \n");
    for (int i = 0; i < theSz; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void prArray(int *arr, int aSz)
{
    int theSz = aSz;
    printf("\nThe array elements are : \n");
    for (int i = 0; i < theSz; i++)
    {
        printf("%d, ", arr[i]);
    }
}