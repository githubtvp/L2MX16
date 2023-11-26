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
void processArray(int *arr, int aSz);

int main()
{
    srand(time(0));
    int theSz;
    printf("\nEnter the no of integer entries in array : ");
    scanf("%d", &theSz);
    int *arr = (int *)malloc(theSz * sizeof(int));
    //  populateArray(arr, theSz);
    populateArrRandomNos(arr, theSz);
    prArray(arr, theSz);
    processArray(arr, theSz);
    free(arr);
    return 0;
}

void processArray(int *arr, int aSz)
{
    int theSz = aSz;
    bool notRepeat = true;
    int newSz = theSz;
    int *notRepeatArr = (int *)malloc(newSz * sizeof(int));
    int notRepeatSz = 0;
    for (int i = 0; i < theSz; i++)
    {
        int theEl = *(arr + i);
        notRepeat = true;
        for (int j = 0; j < theSz && notRepeat; j++)
        {
            if (i == j)
                continue;
            if (theEl == *(arr + j))
            {
                notRepeat = false;
                //  printf("\nItem at i : %d, and at j : %d", theEl, *(arr + j));
                //   printf("\nItem repeated : at %d and %d", i, j);
            }
        }
        if (notRepeat)
        {
            //   printf("\nItem Not repeated : at %d", i);
            notRepeatArr[notRepeatSz] = theEl;
            notRepeatSz++;
        }
    }
    if (notRepeatSz > 0)
    {
        printf("\nThe Non-repeatable elements are : \n");
        for (int i = 0; i < notRepeatSz; i++)
        {
            printf("%d, ", notRepeatArr[i]);
        }
    }
    else
    {
        printf("\nNon-Repeatable items not found");
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
