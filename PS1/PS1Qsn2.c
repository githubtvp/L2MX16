#include <stdio.h>

#define MAXSTARS 10

int convertToOdd(int mStar);
void printBlank(int *maxBlank);
void printStars(int *maxStars);
int main()
{
  int maxStars = convertToOdd(MAXSTARS);
  int currentStars = maxStars;
  int maxBlank = 1;
  do
  {
    printf("\n");
    printBlank(&maxBlank);
    printStars(&currentStars);
  } while (currentStars >= 1);
  printf("\n");
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

void printBlank(int *maxBlank)
{
  for (int i = 0; i < *maxBlank; i++)
  {
    printf(" ");
  }
  *maxBlank += 1;
}

void printStars(int *maxStars)
{
  for (int j = 1; j <= *maxStars; j++)
  {
    printf("*");
  }
  *maxStars -= 2;
}