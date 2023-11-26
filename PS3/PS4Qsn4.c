#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 10

void populateArray(int *arr, int *aSz);
void processArray(int *arr, int aSz);

int main()
{
    // int arr[] = { 2, 5, 8, 4, 2, 5, 1, 4, 7, 3, 6};
    int theSz;
    int *arr;
    printf("\nEnter no of integers to enter for 1 D array :  ");
    scanf("%d", &theSz);
    arr = (int *)malloc(theSz * sizeof(int));
    populateArray(arr, &theSz);
    // theSz = sizeof(arr) / sizeof(int);
    printf("\nMain : Array elemnents are : ");
    for (int i = 0; i < theSz; i++)
    {
        printf("%d  ", arr[i]);
    }
    processArray(arr, theSz);
    free((int*)arr);
    return 0;
}

void processArray(int *arr, int aSz)
{
    int theSz = aSz;
    bool exists = false;
    int foundIndx = 0;
    for (int i = 0; i < theSz - 1; i++)
    {
        int diff = abs(arr[i] - arr[i + 1]);
        if (diff == 1)
        {
            exists = true;
            foundIndx = i;
        }
        if (exists)
            break;
    }
    if (exists)
    {
        printf("\nThe index of the element that meets criteria is : %d "
               " and its value is %d and next value is %d ",
               foundIndx, arr[foundIndx], arr[foundIndx + 1]);
    }
    else
    {
        printf("\nNo such element exists!");
    }
}

void populateArray(int *arr, int *aSz)
{
    int theSz = *aSz;
    printf("\nEnter the %d elements of the array : ", theSz);
    for (int i = 0; i < theSz; i++)
    {
        // scanf("%d", (arr+ i) ); // also works 'coz (arr+i) is address
        scanf("%d", &arr[i]); // also works 'coz &arr[i] is address
    }

    /*printf("\nArray elemnents are : ");
    for (int i = 0; i < theSz; i++)
    {
        printf("%d   ", arr[i]);
    }
    */
    *aSz = theSz;
}