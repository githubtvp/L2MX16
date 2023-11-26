#include <stdio.h>
#include <stdbool.h>
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void processArrElements(int arr[], int aSz);
void printStats(int pos, int neg, int odd, int even, int zero);

int main()
{
  int arrSize, refPosn;
  printf("\nEnter number of integers you will input : ");
  scanf("%d", &arrSize);
  int arr[arrSize];
  populateArray(arr, arrSize);
  printArray(arr, arrSize);
  processArrElements(arr, arrSize);
  printf("\n");
  return 0;
}

void processArrElements(int arr[], int aSz)
{
  int pos = 0, neg = 0, odd = 0, even = 0, zero = 0;
  for (int i = 0; i < aSz; i++)
  {
    if (0 == (arr[i]))
    {
      zero += 1;
    }
    else if (arr[i] < 0)
    {
      neg += 1;
    }
    else if (arr[i] > 0)
    {
      pos += 1;
    }
    int rem = (arr[i] % 2);
    if (0 == rem)
    {
      even += 1;
    }
    else
    {
      odd += 1;
    }
  }
  even = even - zero;
  printStats(pos, neg, odd, even, zero);
}

void printStats(int pos, int neg, int odd, int even, int zero)
{
  printf("\nNo of Zeros : %d", zero);
  printf("\nNo of Positive entries : %d", pos);
  printf("\nNo of Negative entries : %d", neg);
  printf("\nNo of Odd entries : %d", odd);
  printf("\nNo of Even entries : %d", even);
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
