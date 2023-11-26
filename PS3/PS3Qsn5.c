#include <stdio.h>
// Windows: Shift + Alt + F - for formatting
void populateArray(int arr[], int arrSize);
void printArray(int arr[], int arrSize);
void swap(int *arr, int posn1, int posn2);
void sortTheArray(int *arr, int aSz);
int sumArrayElements(int arr[], int aSz, int arrSumEl[], int *aSzNew);

int main()
{
    int arrSize;
    printf("\nEnter number of integers you will input : ");
    scanf("%d", &arrSize);
   //  arrSize = 6;
   //  int arr[6] = {-12, 30,46, -23, -8, 25};
    int arr[arrSize];
    int arrSumEl[arrSize];
    populateArray(arr, arrSize);
    printf("\nThe array elements are :  ");
    printArray(arr, arrSize);
    sortTheArray(arr, arrSize);
    printf("\n");
    printf("\nThe Sorted array elements are :  ");
    printArray(arr, arrSize);

    printf("\n");
    int theSz;
    int sum = sumArrayElements(arr, arrSize, arrSumEl, &theSz);
    printf("\n\nThe lowest sum found =  %d", sum);
    printf("\nformed by the Subset (");
    printArray(arrSumEl, theSz);
    printf(")");
    if (sum < 2)
    {
        printf("\n\nNo subset(containing minimum 2 elements) found whose sum is atleast 2\n\n");
    }
    else
    {
        printf("\n\nThe smallest positive integer that cannot be represented as");
        printf("\nthe sum of any subset(containing minimum 2 elements) of the given array is : %d\n\n", (sum - 1));
    }
    printf("\n");
    return 0;
}

int sumArrayElements(int arr[], int aSz, int arrSumEl[], int *aSzNew)
{
    int theSz = aSz;
    int sum = 0;
    int i = 0;
    int j = 0;
    *aSzNew = 0;
    j = i + 1;
    sum = *(arr + i) + *(arr + j);
    arrSumEl[(*aSzNew)++] = *(arr + i);
    arrSumEl[(*aSzNew)++] = *(arr + j);
    if (sum >= 2)
    {
        return sum;
    }
    else
    {
        j++;
        do
        {
            sum += *(arr + j);
            arrSumEl[(*aSzNew)++] = *(arr + j);
            j++;
        } while (sum < 2 && j < theSz);
    }
    return sum;
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
    for (int i = 0; i < arrSize; i++)
    {
        printf("%4d%s", arr[i], (i < (arrSize - 1) ? "," : ""));
    }
}

void sortTheArray(int *arr, int aSz)
{
    int theSize = aSz;
    int refPosn = 0;
    for (int i = 0; i < theSize - 1; i++)
    {
        refPosn = i;
        for (int j = i + 1; j < theSize; j++)
        {
            if (*(arr + refPosn) > *(arr + j)) // Descending sort
            // if (*(arr + refPosn) < *(arr + j))//Ascending sort
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

void swap(int arr[], int posn1, int posn2)
{
    int temp = arr[posn1];
    arr[posn1] = arr[posn2];
    arr[posn2] = temp;
}
