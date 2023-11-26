#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int sz;
    printf("\nEnter the no of elements to store in array : \n");
    scanf("%d", &sz);
    int *arr = (int*)malloc(sz*sizeof(int));
    printf("\nInput %d number of elements to store in array : \n", sz);
    for(int i =0; i < sz; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    for(int i =0; i < sz; i++)
    {
        sum += arr[i];
    }
    printf("\nThe sum of array : %d", sum);
    printf("\nTest line PS8Qsn2");
    return 0;
}
