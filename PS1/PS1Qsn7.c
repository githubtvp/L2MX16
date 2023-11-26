#include <stdio.h>

#define MAXSTARS 5

void doWhileLoop(int mStars);
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
  int maxStar = mStars;
  int maxBlank = 0;  
  do
  {
    printBlank(maxBlank);
    printStars(maxStar);
    maxStar -= 1;
    maxBlank +=1;
    printf("\n");
  } while (maxStar > 0);
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
