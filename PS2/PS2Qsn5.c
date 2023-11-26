#include <stdio.h>
#include <stdbool.h>
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void shiftArrElements(int arr[], int arrSz, int aTempArr[], int keySz);

int main()
{
    int arrSize, key;
    printf("\nEnter number of integers you will input : ");
    scanf("%d", &arrSize);
    int arr[arrSize];
    populateArray(arr, arrSize);
    printArray(arr, arrSize);
    printf("\nEnter 'Key' value, the number of left shift of array values : ");
    scanf("%d", &key);
    key = key % arrSize;
    int arrTemp[key];
    shiftArrElements(arr, arrSize, arrTemp, key);
    printArray(arr, arrSize);
    printf("\n");
    return 0;
}

void shiftArrElements(int arr[], int arrSz, int aTempArr[], int keySz)
{
    int theArrSize = arrSz, theTempArrSize = keySz;
    if (0 == theTempArrSize)
        return;
    for (int i = 0; i < theTempArrSize; i++)
    {
        aTempArr[i] = arr[i];
    }
    int theStartIndx = theTempArrSize;
    int j = 0;
    for (int i = theStartIndx; i < theArrSize; i++)
    {
        arr[j] = arr[i];
        j++;
    }
    theStartIndx = theArrSize - theTempArrSize;
    j = 0;
    for (int i = theStartIndx; i < theArrSize; i++)
    {
        arr[i] = aTempArr[j];
        j++;
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
