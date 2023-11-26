#include <stdio.h>

#define MAXSTARS 9

int convertToOdd(int mStar);
void printBlank(int maxBlank);
void printStars(int maxStars);
int main()
{
  int maxStars = convertToOdd(MAXSTARS);
  int currentStars = maxStars;
  int fwdBlank = 1;
  int midBlank = currentStars - 4;
printStars(currentStars);
  do
  {
    printf("\n");
    printBlank(fwdBlank);
    printf("*");
    printBlank(midBlank);
    printf("*");
    midBlank-=2;
    fwdBlank+=1;
  } while ( midBlank >= 1);
   printf("\n");
   printBlank(fwdBlank);
   printf("*");
  return 0;
}

int convertToOdd(int mStar)
{
  int mStars;
  if (0 == mStar % 2)
  {
    mStars = mStar + 1;
  }
  else
  {
    mStars = mStar;
  }
  return mStars;
}

void printBlank(int maxBlank)
{
  for (int i = 0; i < maxBlank; i++)
  {
    printf(" ");
  }
}

void printStars(int maxStars)
{
  for (int j = 1; j <= maxStars; j++)
  {
    printf("*");
  }
}
