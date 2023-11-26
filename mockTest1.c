#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

#define MAXSZ 15

void prArr(int aSz, int arr[aSz]);
void getArrEl(int aSz, int arr[aSz]);
void processArr(int aSz, int arr[]);

int main()
{
    int theSz;
    printf("\nEnter size of array less than %d:  ", MAXSZ);
    scanf("%d", &theSz);
    int arr[MAXSZ];
  //  printf("\nEnter the elements of array :  \n");
    getArrEl(theSz, arr);
    prArr(theSz, arr);
    processArr(theSz, arr);
    return 0;
}

void processArr(int aSz, int arr[])
{
    int theSz = aSz;
    bool lesser = true;
    bool greater = true;
    int theCurEl = 0;
    int theIdx;
    for (int i= 1; i < theSz-2 && greater; i++)
    {
            if(arr[i] <= arr[i +1] )
            {
                greater = false;
               // printf("\n arr[i] is %d", arr[i +1]);
                theIdx = i +1;
            }
            else{
                continue;
            }
    }
    if(greater == true)
    {
       printf("\n Output = : %d", -1);
    }
    else{
            for (int i= theIdx; i < theSz-2 && lesser; i++)
            {
                if(arr[theIdx] > arr[i +1] )
                {
                    lesser = false;
                  //  printf("\n arr[i] is %d", arr[i]);
                }
                else{
                    continue;
                }
            }
    }
    if(lesser == false)
    {
       printf("\n Output = : %d", -1);
    }
    else{
       printf("\n The element is : %d at index %d", arr[theIdx], theIdx);
    }
}

void getArrEl(int aSz, int arr[aSz])
{
    int theSz = aSz;
    printf("\nEnter the elements of array :  \n");
    for (int i= 0; i < theSz; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void prArr(int aSz, int arr[aSz])
{
    int theSz = aSz;
     printf("\nArray elements are : \n");
     for (int i= 0; i < theSz; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
