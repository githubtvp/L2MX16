#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_BUF 1000
#define MAXNO 10

void populateArray(int *arr, int aSz);
void populateArrRandomNos(int *arr, int aSz);
void findSumOfElements(int *arr, int aSz);
void prArray(int *arr, int aSz);

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
    findSumOfElements(arr, theSz);
    free(arr);
    return 0;
}

void findSumOfElements(int *arr, int aSz)
{
    int theSz = aSz;
    int theSum = 0;
    int theProduct = 1;
    for (int i = 0; i < theSz; i++)
    {
        theSum += arr[i];
        theProduct *= arr[i];
    }    
  //  printf("\nThe sum of array elements : %d\n",  theSum) ;
  //  printf("\nThe product of array elements : %d\n", theProduct ) ;
    printf("\nThe %s of array elements : %d\n", (0==theSum%2)? "sum" : "produc", (0==theSum%2)? theSum : theProduct ) ;
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