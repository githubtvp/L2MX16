#include <stdio.h>

#define MAXNOOFLINES 5
#define FIRSTCHAR '1'
#define SECONDCHAR '0'

void doWhileLoop(char ftCh, char seCh, int nChar);
void printPairs(char ftCh, char seCh, int nTimes);
void printA_Char(char ch);

int main()
{
  int noOfLines = MAXNOOFLINES;
  char ftChar = FIRSTCHAR;
  char seChar = SECONDCHAR;
  doWhileLoop(ftChar, seChar, noOfLines);
  return 0;
}

void doWhileLoop(char ftCh, char seCh, int nLines)
{
  char ftChar = ftCh;
  char seChar = seCh;
  int noOfLines = nLines;
  int lineNo = 1;
  printA_Char(ftChar);
  printf("\n");
  do
  {
    lineNo += 1;
    int noOfPairs = lineNo / 2;
    if (0 != lineNo % 2)
    {
      printA_Char(ftChar);
    }
    printPairs(ftChar, seChar, noOfPairs);
    printf("\n");
  } while (lineNo < noOfLines);
}

void printPairs(char ftCh, char seCh, int nTimes)
{
  char ftChar = ftCh;
  char seChar = seCh;
  int noOfTimes = nTimes;
  for (int i = 0; i < noOfTimes; i++)
  {
    printA_Char(seChar);
    printA_Char(ftChar);
  }
}

void printA_Char(char ch)
{
  printf("%c", ch);
}
