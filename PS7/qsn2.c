#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
void chkPalindrome(int aNo);
int main()
{
    int theNo;
    printf("\nEnter the integer number : \n");
    scanf("%d", &theNo);
    chkPalindrome(theNo);
   // printf("\ntest line qsn2");
    return 0;
}

void chkPalindrome(int aNo)
{
    int theNo = aNo;
    if(theNo < 0)
    {
         printf("\nFalse");
         return;
    }
    int theCnt =0;
    int theRem;
    int theQt = theNo;
    while(theQt !=0)
    {
        theQt/=10;
        theCnt++;
    }
 //   printf("\ntheCnt : %d", theCnt);
    char arr[theCnt];
   // printf("\nSize : %d", sizeof(arr));
    theQt = theNo;
    for(int i=0; i< theCnt; i++)
    {
        theRem = theQt%10;
        theQt=theQt/10;
      //  printf("\nThe rem : %d", theRem);
        arr[i] = theRem + '0';
    }
    for(int i=0; i< theCnt; i++)
    {
     //  printf("%c  ", arr[i]);
    }
    bool pal = true;
    for(int i=0; i< theCnt/2; i++)
    {
       if(arr[i] != arr[theCnt -1 -i])
       {
           pal = false;
           break;
       };
    }
    printf("Palindrome : %s", (pal)? "True": "False" );
}
