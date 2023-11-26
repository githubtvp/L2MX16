#include <stdio.h>

#define MAXSTARS 5

void doWhileLoop(int mStars);
void printStars(int maxStars);
void printBlank(int maxBlank);

int main()
{
  int maxStars = MAXSTARS;
  doWhileLoop(maxStars);
  printf("\n");
  return 0;
}

void doWhileLoop(int mStars)
{
  int maxStar = mStars;
  int maxBlank = mStars;
  int midBlank = mStars - 2;
  printBlank(maxBlank);
  printStars(maxStar);
  printf("\n");
  do
  {
    maxBlank -= 1;
    printBlank(maxBlank);
    printf("*");
    printBlank(midBlank);
    printf("*");
    printf("\n");
  } while (maxBlank > 2);
  maxBlank-=1;
  printBlank(maxBlank);
  printStars(maxStar);
}

void printStars(int maxStars)
{
  for (int j = 1; j <= maxStars; j++)
  {
    printf("*");
  }
}

void printBlank(int maxBlank)
{
  for (int i = 0; i < maxBlank; i++)
  {
    printf(" ");
  }
}
