#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>

void prArr(int aSz, int arr[aSz]);
void popArr(int aSz, int arr[aSz]);
void prArr2(int *arr, int aSz);
void popArr2(int *arr, int aSz);

int main()
{
    int theSz;
    printf("Enter the size of array : \n");
  //  scanf("%d", &theSz);
  //  int arr[theSz];
  //  popArr(theSz, arr);
   // int arr[theSz] = {1,2,3,4,5};//not allowed
    int arr[] = {1,2,3,4,5, 6, 9};//allowed
    theSz = sizeof(arr)/sizeof(arr[0]);
    prArr(theSz,arr);
 //   int *arr = (int*)malloc(theSz * sizeof(int));
 //   popArr2(arr, theSz);
 //   prArr2(arr, theSz);

   printf("\nTest line\n");
    return  0;
}



void prArr(int aSz, int arr[aSz])
{
    int theSz = aSz;
    for(int i=0; i < theSz; i++)
    {
        printf("%d,  ", arr[i]);
    }
}

void popArr(int aSz, int arr[aSz])
{
    int theSz = aSz;
    printf("\nEnter array elements :\n");
    for(int i=0; i < theSz; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void prArr2(int *arr, int aSz)
{
    int theSz = aSz;
    for(int i=0; i < theSz; i++)
    {
        printf("%d,  ", arr[i]);
    }
}

void popArr2(int *arr, int aSz)
{
    int theSz = aSz;
    printf("\nEnter array elements :\n");
    for(int i=0; i < theSz; i++)
    {
        scanf("%d", &arr[i]);
    }
}


