#include <stdio.h>

#define MAXSTARS 5

void doWhileLoop(int mStars);
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
  int maxStar = 1;
  do
  {
    printStars(maxStar);
    maxStar += 1;
    printf("\n");
  } while (maxStar <= mStars);

  maxStar -= 2;
  do
  {
    printStars(maxStar);
    maxStar -= 1;
    printf("\n");
  } while (maxStar >= 1);
}

void printStars(int maxStars)
{
  for (int j = 1; j <= maxStars; j++)
  {
    printf("*");
  }
}
