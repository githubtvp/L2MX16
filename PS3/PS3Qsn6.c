#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUF 1000

void getTheStringSeries(char aStr[], int *aSz);
void countChar(char aStr[], int aSz, int *lwArr);
void matchAndUpdateCounts(int *chArr, char aCh, bool upp);
void printCountsArray(int *arr, int aSz);

int main()
{
    char theStr[MAX_BUF];
    int theSz =0; 
    getTheStringSeries(theStr, &theSz);
    printf("\nIn Main : ");
    puts(theStr);//prints all char except the last null char '\0' and a new line char is auto printed
    printf("\n"); // so cursor goes to next line after print
    int theCountArr[26] = {};
    countChar(theStr, theSz, theCountArr);
    printCountsArray(theCountArr, 26);
    return 0;
}

void getTheStringSeries(char aStr[], int *aSz)
{
   printf("\nEnter the series of strings :  \n");
   fgets(aStr, MAX_BUF, stdin);//accepts strings with spaces also until a new line character is encountered 
   int cnt=0; //it rejects the new line character and appends the null character '\0' at end
   while(aStr[cnt] != '\0')
    {
        cnt++;
    }
    *aSz = cnt;
    printf("\nTotal characters entered : %d", cnt);
}

void countChar(char aStr[], int aSz, int *cntArr)
{
    bool upper = true;
    printf("\n");
    for (int i = 0; i < aSz; i++)
    {
        char theCh = aStr[i];
        if (theCh >= 'A' && theCh <= 'Z')
        {
            upper = true;
        }
        else if (theCh >= 'a' && theCh <= 'z')
        {
            upper = false;
        }
        else
        {
            continue;
        }
        matchAndUpdateCounts(cntArr, theCh, upper);
    }  
    printf("\n");
}

void matchAndUpdateCounts(int *chArr, char aCh, bool upp)
{
    bool upper = upp;
    int theStCh;
    int theEndCh;
    int theOffset;
    char theCh = aCh;
    if (upper)
    {
        theStCh = 65;
        theEndCh = 90;
        theOffset = 0;
    }
    else
    {
        theStCh = 97;
        theEndCh = 122;
        theOffset = 26;
    }
    for (char ch = theStCh; ch <= theEndCh; ch++)
    {
        if (theCh == ch)
        {
            int indx = theCh - theStCh;
            chArr[indx]++;
        }
    }
}

void printCountsArray(int *arr, int aSz)
{
    int theSz = aSz;
    int theOffSet = 65;
    printf("\nDistribution of letters in corpus :\n");
    for (int i = 0; i < theSz; i++)
    {      
        char ch = i + theOffSet;
        printf("\n%c : %d \n", ch, arr[i]);
    }
}
