#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAXNUM 25
// Windows: Shift + Alt + F - for formatting

void copyArray(int arrOrig[], int aSz, int arrCopy[], int *aCopySz);
void removeDuplicatesInArray(int *arr, int *aSz);
void shiftLeftArrElements(int *arr, int arrSz, int aStPosn);
int min_k(int arr[], int arrSize, int aKno);

void populateArrayRandom(int *arr, int aSz);
void populateArray(int arr[], int arrSize);
void printArray(int *arr, int aSz);
void selectionSortArray(int arr[], int arrSize);
void swap(int *arr, int posn1, int posn2);

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
    // selectionSortArray(arr, arrSize);
    // printf("\nOriginal Array : ");
    //  printArray(arr, arrSize);
    printf("\n");
    int arrCopySize = arrSize;
    int arrCopy[arrCopySize];
    copyArray(arr, arrSize, arrCopy, &arrCopySize);
    printf("\nCopy of Original Array : ");
    printArray(arrCopy, arrCopySize);
    printf("\n");
    removeDuplicatesInArray(arrCopy, &arrCopySize);
    printf("\nCopied Array after removal of Duplicates : ");
    printArray(arrCopy, arrCopySize); // arrDuplSize
    printf("\n\n");
    // printArray(arrLessDupl, arrDuplSize);
    printf("\n");
    int kthMin = min_k(arrCopy, arrCopySize, kNo);
    printf("\n");
    selectionSortArray(arrCopy, arrCopySize);
    printf("\nOriginal Array sorted and less the duplicates: ");
    printArray(arrCopy, arrCopySize);
    printf("\n%d %s Kth Minimum : %d", kNo, (kNo < 4 ? (kNo < 3 ? "nd" : "rd") : "th"), kthMin);
    printf("\n");
    return 0;
}

void copyArray(int arrOrig[], int aSz, int arrCopy[], int *aCopySz)
{
    int theSz = aSz;
    for (int i = 0; i < theSz; i++)
    {
        arrCopy[i] = arrOrig[i];
    }
    *aCopySz = theSz;
}

void removeDuplicatesInArray(int *arr, int *aSz)
{
    int theSize = *aSz;
    int refPosn = 0;
    bool found = false;
    for (int i = 0; i < theSize - 1; i++)
    {
        for (int j = i + 1; j < theSize; j++)
        {
            if (*(arr + i) == *(arr + j))
            {
                found = true;
                shiftLeftArrElements(arr, theSize, j);
                theSize--;
                j--;
            }
        }
    }
    *aSz = theSize;
    if (!found)
    {
        printf("\nNo duplicates were found in the Array\n");
    }
    else
    {
        printf("\nAll duplicates removed from the Array\n");
    }
}

void shiftLeftArrElements(int *arr, int arrSz, int aStPosn)
{
    int theArrSize = arrSz;
    int theStartIndx = aStPosn;
    int theStIndx = theStartIndx;
    for (int i = theStIndx + 1; i < theArrSize; i++)
    {
        *(arr + theStIndx) = *(arr + i);
        theStIndx++;
    }
}

int min_k(int arr[], int arrSize, int aKno)
{
    int kMinimum;
    int theKno = aKno;
    int theSize = arrSize;
    int theMinPosn = 0;
    int theCnt = 0;
    bool exch = false;
    for (int i = 0; i < theSize && theCnt < theKno; i++)
    {
        exch = false;
        theMinPosn = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[theMinPosn] > arr[j])
            {
                theMinPosn = j;
                exch = true;
            }
        }
        if (exch)
        {
            swap(arr, i, theMinPosn);
            theCnt++;
        }
    }
    kMinimum = arr[theKno - 1];
    return kMinimum;
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
        theVal = rand() % MAXNUM + 1;
        *(arr + i) = theVal;
    }
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

