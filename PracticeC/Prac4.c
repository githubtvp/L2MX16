#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

#define MAXLEN 100
void strrev2(char str[]);
void substr1(char str[]);
void getLine(char str[], int aBufSz, int *aSz);

int main()
{
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   // printf("\n%s", str1);
    char str2[] = "Hello World";
 //   printf("\n%s", str2);
 //   printf("\n%d", strlen(str2) );
 //   printf("\n%s", strrev(str2) );
    strrev2(str2);
    substr1(str2);
  //  int arr[MAXLEN];
  //  printf("\nLen of Arr : %d ", sizeof(arr));

     char ch;
     printf("\nEnter a ch: \n");
     scanf("%c", &ch);
     printf("\nChar ch : %c", ch);

     char str3[10];
 //    printf("\nEnter a str: \n");
  //   scanf("%s", str3);// & need not be included for string inputs
 //    printf("\nStr str  : %s", str3);

     int lnSz = 0;
     char aLine[MAXLEN];
   //  printf("\nEnter a Line: \n");
  //   getLine(aLine, MAXLEN, &lnSz);
 //    printf("\nThe line is : %s ", aLine);
 //    puts(aLine);

    return 0;
}

void getLine(char str[], int aBufSz, int *aSz)
{
    //getchar();//only if previous entry left a \n
    fgets(str, aBufSz, stdin);//discards the \n entry
    int cnt=0;
    while(str[cnt] != '\0')
    {
        cnt++;
    }
    *aSz = cnt;
    printf("\nNo of char in line : %d", *aSz);
}

void substr1(char str[])
{
  //  char str1 = str.substr(3, 4);
 //  printf("\n%s", str1);
}

void strrev2(char str[])
{
  // printf("\nHere 1");
    int st =0; int end = 0;
    end = strlen(str);
    printf("\n%d , len", end);
    end--;
    while(st < end)
    {
        char temp = str[st];
        str[st] =  str[end];
        str[end] = temp;
        st++; end--;
        printf("\nHere 1");
    }
    printf("\n%s", str);
}


