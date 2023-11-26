#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 10

void populateArray(int *arr, int *aSz);

int main()
{
    int theSz;
    int *arr;
    printf("\nEnter no of integers to enter for 1 D array :  ");
    scanf("%d", &theSz);
    arr = (int *)malloc(theSz * sizeof(int));
    populateArray(arr, &theSz);
    printf("\nMain : Array elemnents are : ");
    for (int i = 0; i < theSz; i++)
    {
        printf("%d  ", arr[i]);
    }
    free((int*)arr);
    return 0;
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