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
void processArr(int *arr, int aSz);

int main()
{
    srand(time(0));
    int theSz;
    printf("\nEnter the no of entries in array : ");
    scanf("%d", &theSz);
    int *arr = (int *)malloc(theSz * sizeof(int));
    //  populateArray(arr, theSz);
    populateArrRandomNos(arr, theSz);
    prArray(arr, theSz);
    processArr(arr, theSz);
    printf("\nArray after shifting 0's to end of array :");
    prArray(arr, theSz);
    free(arr);
    return 0;
}

void processArr(int *arr, int aSz)
{
    int theSz = aSz;
    int theEl;
    for (int i = 0; i < theSz; i++)
    {
        theEl = *(arr + i);        
        if (0 == *(arr + i))
        {
            for (int j = i; j < theSz - 1; j++)
            {
                *(arr + j) = *(arr + j + 1);
            }
            theSz--;
            i--;            
        }
    }  
    for(int i = theSz; i < aSz; i++)
    {
        *(arr + i) = 0;
    } 
}

void populateArrRandomNos(int *arr, int aSz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        int theVal = rand() % MAXNO;
        int theVal2 = rand() % 3;
        (0 == theVal2) ? theVal = 0 : 0;
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
