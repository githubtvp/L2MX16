#include <stdio.h>

#define MAXSTARS 5

void doWhileLoop(int mStars);
void print(int mStar, int mBlank);
void printBlank(int maxBlank);
void printStars(int maxStars);

int main()
{
  int maxStars = MAXSTARS;
  doWhileLoop(maxStars);  
  printf("\n");
  return 0;
}

void doWhileLoop(int mStars)
{
  int maxStar = 0;
  int maxBlank = mStars;
  do
  {
    print(maxStar, maxBlank);
    maxBlank -=1;
    maxStar += 1;
    printf("\n");
  } while (maxBlank >= 0);

  maxStar = mStars;
  maxBlank = 0;
  
  do
  {
    print(maxStar, maxBlank);
    maxBlank +=1;
    maxStar -= 1;
    printf("\n");
  } while (maxStar >= 1);
}


void print(int mStar, int mBlank)
{
  int maxStar = mStar;
  int maxBlank = mBlank;
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

