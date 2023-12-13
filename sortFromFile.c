#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// argc => argument count, argv => argument value

void sortArr(int *arr, int sz);
void prArr(int *arr, int sz);
int main() // int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    FILE *fp3;
    // char *fname1;
    char *fname1 = "test1.txt";
    char *fname2 = "test2.txt";
    char *fname3 = "test3.txt";
    // fgets(fname1, 100, stdin);
    //  printf("%s", fname1);
    //  fname1 = argv[1];
    //  fname2 = argv[2];
    //  fname2 = argv[3];
    int *arr1, *arr2;
    int n = 6;
    int *arr3;
    arr3 = (int*)malloc(20*sizeof(int));
    arr1 = (int *)malloc(10 * sizeof(int));
    arr2 = (int *)malloc(10 * sizeof(int));
    fp1 = fopen(fname1, "r");
    fp2 = fopen(fname2, "r");
    fp3 = fopen(fname3, "w");
    int i = 0;
    printf("\n");
    // while (fscanf(fp1, "%d", &arr1[i]) != EOF)
    // { // printf("\n1. Test line  ");
    //     printf("%d  ", arr1[i]);
    //     i++;
    // }
    // sortArr(arr1, n);
    // printf("\nSorted arr1 : ");  
    // prArr(arr1, n); 
    // printf("\n");
    // i = 0;
    // while (fscanf(fp2, "%d", &arr2[i]) != EOF)
    // { // printf("\n1. Test line  ");
    //     printf("%d  ", arr2[i]);
    //     i++;
    // }     
    // sortArr(arr2, n);
    // printf("\nSorted arr 2: ");
    // prArr(arr2, n);
    i = 0;
    printf("\n");
    while (fscanf(fp1, "%d", &arr3[i]) != EOF)
    { 
        i++;
    }
    while (fscanf(fp2, "%d ", &arr3[i]) != EOF)
    { 
        i++;
    }
    sortArr(arr3, i);
    printf("\nSorted arr 3: ");
    prArr(arr3, i);
    printf("\nInsert into file : ");

    for(int j=0; j < i; j++)
    {
        fprintf(fp3, "%d  ", arr3[j]);
        printf("%d ", arr3[j]);
    }


    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("\nTest line");
    return 0;
}

void sortArr(int *arr, int sz)
{
    for (int i = 0; i < sz - 1; i++)
    { // printf("\nTest line");

        int minIndx = i;
        for (int j = i + 1; j < sz; j++)
        { // printf("\n2. Test line");
            if (arr[minIndx] > arr[j])
            {
                minIndx = j;
            }
        }
        if (i != minIndx)
        {
            int temp = arr[minIndx];
            arr[minIndx] = arr[i];
            arr[i] = temp;
        }
    }
}

void prArr(int *arr, int sz)
{
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}