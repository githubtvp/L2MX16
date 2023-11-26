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
void splitArr(int *arr, int aSz, int *arr2, int a2Sz);

int main()
{
    srand(time(0));
    int theSz, theSplitPosn;
    printf("\nEnter the no of integer entries in array : ");
    scanf("%d", &theSz);
    int *arr = (int *)malloc(theSz * sizeof(int));
    //  populateArray(arr, theSz);
    populateArrRandomNos(arr, theSz);
    prArray(arr, theSz);

    printf("\nEnter the position to split the array : ");
    scanf("%d", &theSplitPosn);
    int arr2Sz = (theSplitPosn);
    int *arr2 = (int *)malloc(arr2Sz * sizeof(int));
    splitArr(arr, theSz, arr2, arr2Sz);

    printf("\nThe array elements after split and re-joining : ");
    prArray(arr, theSz);
    free(arr);
    return 0;
}

void splitArr(int *arr, int aSz, int *arr2, int a2Sz)
{
    int theSz = aSz;
    int arr2Sz = a2Sz;
    for (int i = 0; i < arr2Sz; i++)
    {
        *(arr2 + i) = *(arr + i);
    }
    for (int i = arr2Sz, j = 0; i < theSz; i++, j++)
    {
        *(arr + j) = *(arr + i);
    }
    for (int i = (theSz - arr2Sz), j = 0; i < theSz; i++, j++)
    {
        *(arr + i) = *(arr2 + j);
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