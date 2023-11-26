#include <stdio.h>
#include <stdbool.h>
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
// void selectionSortArray(int arr[], int arrSize);
void getSortedArray(int arr[], int arrSize, bool asc);
void swap(int *arr, int posn1, int posn2);

int main()
{
  int arrSize, refPosn;
  printf("\nEnter number of integers you will input : ");
  scanf("%d", &arrSize);
  int arr[arrSize];
  populateArray(arr, arrSize);
  printArray(arr, arrSize);
  bool asc = true;
  getSortedArray(arr, arrSize, asc);
  printf("\nArray in Ascending order : ");
  printArray(arr, arrSize);
  asc = false;
  printf("\nArray inDescending order : ");
  getSortedArray(arr, arrSize, asc);
  printArray(arr, arrSize);
  printf("\n");
  return 0;
}

void populateArray(int arr[], int arrSize)
{
  printf("\nEnter array elements : \n");
  for (int i = 0; i < arrSize; i++)
  {
    scanf("%d", &arr[i]);
  }
}

void printArray(int arr[], int arrSize)
{
  printf("\nThe array elements are :  ");
  for (int i = 0; i < arrSize; i++)
  {
    printf("%4d", arr[i]);
  }
}

void getSortedArray(int arr[], int arrSize, bool asc)
{
  int secondHighest;
  for (int i = 0; i < arrSize - 1; i++)
  {
    for (int j = i + 1; j < arrSize; j++)
    {
      if (asc)
      {
        if (arr[i] > arr[j]) // Ascending order
          swap(arr, i, j);
      }
      else
      {
        if (arr[i] < arr[j]) // Descending order
          swap(arr, i, j);
      }
    }
  }
}

void swap(int arr[], int posn1, int posn2)
{
  int temp = arr[posn1];
  arr[posn1] = arr[posn2];
  arr[posn2] = temp;
}
/*
void selectionSortArray(int arr[], int arrSize)
{
  int refPosn;
  for (int i = 0; i < arrSize - 1; i++)
  {
    refPosn = i;
    for (int j = i + 1; j < arrSize; j++)
    {
      // if (arr[refPosn] < arr[j]) // Descending order
      if (arr[refPosn] > arr[j]) // Ascending order
        refPosn = j;
    }
    if (refPosn != i)
    {
      swap(arr, refPosn, i);
    }
  }
}
*/