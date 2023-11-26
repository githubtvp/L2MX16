#include <stdio.h>

#define MAXSTARS 10

int convertToEven(int mStar);
void doWhileLoop(int mStars);
void print(int mStar, int mBlank);
void printBlank(int maxBlank);
void printStars(int maxStars);

int main()
{
  int maxStars = convertToEven(MAXSTARS);
  doWhileLoop(maxStars);
  printf("\n");
  return 0;
}

int convertToEven(int mStar)
{
  int mStars;
  if (0 == mStar % 2)
  {
    mStars = mStar;
  }
  else
  {
    mStars = mStar + 1;
  }
  return mStars;
}

void doWhileLoop(int mStars)
{
  int maxStar = mStars;
  int maxBlank = 0;
  printStars(maxStar);
  maxStar = maxStar / 2 - 1;
  do
  {
    printf("\n");
    maxBlank += 2;
    print(maxStar, maxBlank);
    maxStar -= 1;
  } while (maxStar > 0);
  maxStar = 1;
  printf("\n");
  do
  {
    print(maxStar, maxBlank);
    maxStar += 1;
    maxBlank -= 2;
    printf("\n");
  } while (maxStar < mStars / 2);
  maxStar = mStars;
  printStars(maxStar);
}

void print(int mStar, int mBlank)
{
  int maxStar = mStar;
  int maxBlank = mBlank;
  printStars(maxStar);
  printBlank(maxBlank);
  printStars(maxStar);
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
