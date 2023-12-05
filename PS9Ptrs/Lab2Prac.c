#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 25

void qsn1();
void qsn2();
void ps10qsn1();
void ps10qsn2();
int main()
{
    //ps10qsn2();
    ps10qsn1();
    // ps10qsn1();
    //  qsn2();
    //   qsn1();
    printf("\nTestline ");
    return 0;
}

void ps10qsn2()
{
    char *str1;
    // char *str2;
    int n1 = 15, n2 = 15;
    str1 = (char *)malloc(n1 * sizeof(char));
    // str2 = (char *)malloc(n2 * sizeof(char));
    printf("\nEnter the string : \n");
    fgets(str1, MAX, stdin);
    // fgets(str2, MAX, stdin);
    int i, j;
    bool found = true;
    for (i = 0; i < n1-1 && found; i++)
    {
        for (j = i+1; j < n1; j++)
        {
            if (str1[i] == str1[j])
            {
                printf("\nat i : %d", i);
                break;
            }
        }
        if (j == n1)
        {
            found = false;
            break;
        }
    }
    if (!found)
        printf("\nFirst non repating char is %c, at index %d", str1[i], i);
      // else
    //     printf("\nThey are Anagram");
}

void ps10qsn1()
{
    char *str1;
    char *str2;
    int n1 = 10, n2 = 10;
    str1 = (char *)malloc(n1 * sizeof(char));
    str2 = (char *)malloc(n2 * sizeof(char));
    printf("\nEnter the 2 strings : \n");
    fgets(str1, MAX, stdin);
    fgets(str2, MAX, stdin);
    if (strlen(str1) != strlen(str2))
    {
        printf("\n1. Not Anagram");
    }
    else
    {
        int i, j;
        bool anag = true;
        for (int i = 0; i < n1 && anag; i++)
        {
            for (j = 0; j < n2; j++)
            {
                if (str1[i] == str2[j])
                {
                    break;
                }
            }
            if (j >= n2)
            {
                anag = false;
                break;
            }
        }
        if (!anag)
            printf("\n2. Not Anagram");
        else
            printf("\nThey are Anagram");
    }
}

void qsn2()
{
    char *name1 = (char *)malloc(MAX * sizeof(char));
    // char *name2 = (char*)malloc(MAX * sizeof(char));
    printf("Enter name : ");
    fgets(name1, MAX, stdin);
    int len = strlen(name1);
    // printf("%d", len);
    printf("\n%s", name1);
    char name2[MAX];
    for (int i = len, j = 0; i >= 0; i--, j++)
    {
        name2[j] = name1[i];
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c ", name2[i]);
    }
    free(name1);
    //  free(name2);
}
void qsn1()
{
    int a1 = 5, a2 = 5;
    int *arr1;
    int *arr2;
    arr1 = (int *)malloc(a1 * sizeof(int));
    arr2 = (int *)malloc(a2 * sizeof(int));
    printf("\nEnter arr 1 elements : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter arr 2 elements : \n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr2[i]);
    }
    // int *ptr1, *ptr2;
    // ptr1 = arr1;
    // ptr2 = arr2;
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr1[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d", arr2[i]);
    }

    bool matched = true;
    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] != arr2[i])
        {
            matched = false;
            break;
        }
    }

    if (matched)
    {
        printf("\nThey are same");
    }
    else
    {
        printf("\nThey are Not same");
    }

    printf("\nreversed\n");
    for (int i = 4; i >= 0; --i)
    {
        printf("\n%d", arr2[i]);
    }
}