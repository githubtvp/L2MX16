#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int sz;
    printf("\nEnter the no of elements to store in the array : ");
    scanf("%d", &sz);
    int *arr = (int *)malloc(sz * sizeof(int));
    printf("\nInput %d integer values to store in array : \n", sz);
    for (int i = 0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nThe elements you entered are : \n");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    //  printf("\nTest line PS8Qsn1");
    return 0;
}
