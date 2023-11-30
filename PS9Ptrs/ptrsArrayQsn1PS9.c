#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 15
int main()
{
    int arr1[MAX];
    int arr2[MAX];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int *ptr1, *ptr2;
    ptr1 = arr1;
    ptr2 = arr2;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(ptr1 + i));
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", *(ptr2 + i));
    }

    bool matched = true;
    for (int i = 0; i < 5; i++)
    {
        if (*(ptr2 + i) != *(ptr1 + i))
        {
            matched = false;
            break;
        }
    }
    printf("\nreversed\n");
    for (int i = 5; i >= 0; --i)
    {
        printf("\n%d", *(ptr2 + i));
    }

    if (matched)
    {
        printf("\nThey are same");
    }
    else
    {
        printf("\nThey are Not same");
    }
    /*
        int *ptr1 = (int *)malloc(MAX * sizeof(int));
        int *ptr2 = (int *)malloc(MAX * sizeof(int));
        printf("Enter name : ");
        gets(ptr);
        int len=strlen(ptr);
        printf("%d", len);
        printf("\n%s", ptr);
        //intInput();
        printf("\nTestline ");
        free(ptr);
        */
    return 0;
}
