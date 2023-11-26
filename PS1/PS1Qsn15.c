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
  int midBlank = 0; //mStars - 2;
  printf("*");
  printf("\n");
  do
  {
    printf("*");
    printBlank(midBlank);
    printf("*");
    midBlank += 1;
    printf("\n");
  } while (midBlank < mStars-2) ;
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
