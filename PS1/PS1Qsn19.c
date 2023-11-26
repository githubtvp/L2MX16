#include <stdio.h>
#include <stdbool.h>

#define NOOFCHARS 5
#define STARTCHAR 'A'

void doWhileLoop(char startCh, int nChar);
void printRemainingLines(char ch, int nChar);
void printChSeries(char *ch, int nPr, bool incr);
void printBlank(int maxBlank);
void printA_Char(char ch);

int main()
{
  int noOfChar = NOOFCHARS;
  char startChar = STARTCHAR;
  doWhileLoop(startChar, noOfChar);
  return 0;
}

void doWhileLoop(char startCh, int nChar)
{
  char startChar = startCh;
  int cnt = 0;
  int noOfChar = nChar;
  int noOfFwdChar = noOfChar;
  int noOfRevChar = noOfFwdChar - 1;
  do
  {
    printA_Char(startChar);
    startChar += 1;
    cnt += 1;
  } while (cnt < noOfFwdChar);
  startChar -= 1;
  cnt = 0;
  do
  {
    startChar -= 1;
    printA_Char(startChar);
    cnt += 1;
  } while (cnt < noOfRevChar);
  printf("\n");
  printRemainingLines(startChar, noOfChar);
}

void printRemainingLines(char aCh, int nChar)
{
  char ch = aCh;
  int noOfChar = nChar;
  int maxBlank = 1;
  int noOfFwdChar = noOfChar - 1;
  bool incr = true;
  do
  {
    incr = true;
    printChSeries(&ch, noOfFwdChar, incr);
    printBlank(maxBlank);
    ch -= 1;
    incr = false;
    printChSeries(&ch, noOfFwdChar, incr);
    maxBlank += 2;
    noOfFwdChar -= 1;
    ch += 1;
    printf("\n");
  } while (noOfFwdChar > 0);
}

void printChSeries(char *ch, int noOfChar, bool incr)
{
  int noOfFwdChar = noOfChar;
  do
  {
    printf("%c", *ch);
    if (incr)
    {
      *ch += 1;
    }
    else
    {
      *ch -= 1;
    }
    noOfFwdChar -= 1;
  } while (noOfFwdChar > 0);
}

void printBlank(int maxBlank)
{
  for (int i = 0; i < maxBlank; i++)
  {
    printf(" ");
  }
}

void printA_Char(char ch)
{
  printf("%c", ch);
}
