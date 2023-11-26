#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

void getInput(char *arr);
void matchStr(char *lStr, char *sStr);
int main()
{
    char sStr[] = {"test"};
    char *ptrLs; 
    printf("\nEnter the long string : ");
    getInput(ptrLs);
    printf("\nThe test line is  :\n%s", ptrLs);
    matchStr(ptrLs, sStr);
    //    printf("\nTest line PS8 Qsn 4");
}

void matchStr(char *ptrLs, char *sStr)
{
    int len1 = strlen(ptrLs);
    int len2 = strlen(sStr);
    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        if (ptrLs[i] == sStr[0])
        {
            //  printf("\nFirst char match at index : %d", i);
            int k = i;
            bool matchFound = true;
            for (int j = 0; j < len2; j++, k++)
            {
                if (sStr[j] != ptrLs[k])
                {
                    // printf("\nNot match");
                    matchFound = false;
                    break;
                }
            }
            if (matchFound)
            {
                // printf("\nMatch Found at : %d", i);
                count++;
                i = k;//start from new point
            }
        }
    }
    printf("\nTotal matches found : %d", count);
}

void getInput(char *arr)
{
    fgets(arr, MAX, stdin);
}
