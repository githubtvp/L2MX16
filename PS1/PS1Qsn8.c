#include <stdio.h>

#define MAXLEN 10

int convertToOdd(int mLen);
void doWhileLoop(int mLen);
void print(int fBlk, int mBlk);
void printBlank(int maxBlank);

int main()
{
  int maxLen = convertToOdd(MAXLEN);
  doWhileLoop(maxLen);
  printf("\n");
  return 0;
}

int convertToOdd(int mLen)
{
  int maxLen;
  if (0 == mLen % 2)
  {
    maxLen = mLen + 1;
  }
  else
  {
    maxLen = mLen;
  }
  return maxLen;
}

void doWhileLoop(int mLen)
{
  int maxLen = mLen;
  int midPt = maxLen / 2 + 1;
  int fwdBlank = midPt - 1;
  int midBlank = 1;
  printf("\n");
  printBlank(fwdBlank);
  printf("*");
  do
  {
    fwdBlank -= 1;
    print(fwdBlank, midBlank);
    midBlank += 2;
  } while (fwdBlank > 0);

  fwdBlank = 1;
  midBlank -= 2;
  do
  {
    midBlank -= 2;
    print(fwdBlank, midBlank);
    fwdBlank += 1;
  } while (fwdBlank < 5);
  printf("\n");
  fwdBlank = midPt - 1;
  printBlank(fwdBlank);
  printf("*");
}

void print(int fBlk, int mBlk)
{
  int fwdBlank = fBlk;
  int midBlank = mBlk;
  printf("\n");
  printBlank(fwdBlank);
  printf("*");
  printBlank(midBlank);
  printf("*");
}

void printBlank(int maxBlank)
{
  for (int i = 0; i < maxBlank; i++)
  {
    printf(" ");
  }
}