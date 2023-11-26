#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void populateArrayRandom(int *arr, int aSz);
int getKthLargest(int arr[], int arrSize, int aKno);
void printArray(int *arr, int aSz);
void swap(int *arr, int posn1, int posn2);

// void selectionSortArray(int arr[], int arrSize);
// void sortTheArray(int *arr, int aSz);
// bool elementFoundInArray(int arr[], int aSz, int aVal);

int main()
{
    time_t theSeed;
    srand((unsigned)time(&theSeed));
    int arrSize, refPosn, kNo;
    printf("\nEnter number of integers you will input : ");
    scanf("%d", &arrSize);
    do
    {
        printf("\nEnter the 'K' number of the largest (a Value between 1 and %d )  :  ", arrSize);
        scanf("%d", &kNo);
    } while ((kNo < 1) || (kNo > arrSize));

    int arr[arrSize];
    populateArrayRandom(arr, arrSize);
    printArray(arr, arrSize);
    int kthLargest = getKthLargest(arr, arrSize, kNo);
    printf("\n");
    printArray(arr, arrSize);
    printf("\n%d %s Largest: %d", kNo, (kNo < 4 ? (kNo < 3 ? "nd" : "rd") : "th"), kthLargest);
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

void populateArrayRandom(int *arr, int aSz)
{
    int theSize = aSz;
    int theVal = 0;
    for (int i = 0; i < theSize; i++)
    {
        theVal = rand() % MAXNUM;
        theVal++;
        *(arr + i) = theVal;
    }
}

int getKthLargest(int arr[], int arrSize, int aKno)
{
    int kLargest;
    int theKno = aKno;
    int theSize = arrSize;
    int theLgPosn = 0;
    int theCnt = 0;
    bool exch = false;
    for (int i = 0; i < theSize && theCnt < theKno; i++)
    {
        exch = false;
        theLgPosn = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[theLgPosn] < arr[j])
            {
                theLgPosn = j;
                exch = true;
            }
        }
        if (exch)
        {
            swap(arr, i, theLgPosn);
            theCnt++;
        }
    }
    kLargest = arr[theKno - 1];
    return kLargest;
}

void printArray(int *arr, int aSz)
{
    int theSize = aSz;
    for (int i = 0; i < theSize; i++)
    {
        printf("%d\t", *(arr + i));
    }
}

void swap(int *arr, int posn1, int posn2)
{
    int temp = *(arr + posn1);
    *(arr + posn1) = *(arr + posn2);
    *(arr + posn2) = temp;
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

/*
bool elementFoundInArray(int arr[], int aSz, int aVal)
{
    int theSize = aSz;
    int theVal = aVal;
    bool found = false;
    for (int i = 0; i < theSize && !found; i++)
    {
        if (theVal == arr[i])
        {
            found = true;
        }
    }
    return found;
}
*/

/*
void sortTheArray(int *arr, int aSz)
{
    int theSize = aSz;
    int refPosn = 0;
    for (int i = 0; i < theSize - 1; i++)
    {
        refPosn = i;
        for (int j = i + 1; j < theSize; j++)
        {
            if (*(arr + refPosn) > *(arr + j))
            {
                refPosn = j;
            }
        }
        if (refPosn != i)
        {
            swap(arr, i, refPosn);
        }
    }
}
*/
