#include <stdio.h>
#include <stdbool.h>
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void getIndexOfValueToSearch(int arr[], int aSz);

int main()
{
  int arrSize, refPosn;
  printf("\nEnter number of integers you will input : ");
  scanf("%d", &arrSize);
  int arr[arrSize];
  populateArray(arr, arrSize);
  printArray(arr, arrSize);
  getIndexOfValueToSearch(arr, arrSize);
  printf("\n");
  return 0;
}

void getIndexOfValueToSearch(int arr[], int aSz)
{
  int theVal;
  bool found = false;
  printf("\nEnter the element value in the Array to search for its position : ");
  scanf("%d", &theVal);
  for (int i = 0; i < aSz; i++)
  {
    if (theVal == arr[i])
    {
      printf("\nThe element : %d exists at index position %d : ", theVal, i);
      return;
    }
    else if (!found && (i == (aSz - 1)))
    {
      printf("\nThe element value : %d entered does not exist in the array. Quitting!", theVal);
    }
  }
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
