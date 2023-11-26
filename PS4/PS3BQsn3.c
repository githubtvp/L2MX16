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
void prArray(int *arr, int aSz);
void processArray(int *arr, int aSz, int aSum);
int main()
{
    srand(time(0));
    int theSz, theSum;
    printf("\nEnter the no of integer entries in array : ");
    scanf("%d", &theSz);
    int *arr = (int *)malloc(theSz * sizeof(int));
    //  populateArray(arr, theSz);
    populateArrRandomNos(arr, theSz);
    prArray(arr, theSz);

    printf("\nEnter the Sum of two elements to be found : ");
    scanf("%d", &theSum);
    processArray(arr, theSz, theSum);
    free(arr);
    return 0;
}

void processArray(int *arr, int aSz, int aSum)
{
    int theSz = aSz;
    int theSum = aSum;
    bool notFound = true;
    int indx1, indx2;
    for (int i = 0; i < theSz - 1 && notFound; i++)
    {
        int theElsSum = *(arr + i);
        for (int j = i + 1; j < theSz && notFound; j++)
        {
            if (theSum == (theElsSum + *(arr + j)))
            {
                notFound = false;
                indx1 = i;
                indx2 = j;
            }
        }
    }
    if (!notFound)
    {
        printf("\nPair found at index %d and %d", indx1, indx2);
    }
    else
    {
        printf("\nPair not found!");
    }
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
