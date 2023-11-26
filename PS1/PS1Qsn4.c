#include <stdio.h>
#include <stdbool.h>

#define MAXSTARS 10

int convertToOdd(int mStar);
void printStraight(int mStar);
void printInverted(int mStar);
void printBlank(int *maxBlank, bool incr);
void printStars(int *maxStars, bool incr);
void doWhileLoop(int maxBlank, int currentStars, int maxStars, bool straight);

int main()
{
  int maxStars = convertToOdd(MAXSTARS);
  printStraight(maxStars);
  printInverted(maxStars);
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

void printStraight(int mStar)
{
  int maxStars = mStar;
  int maxBlank = maxStars / 2;
  int currentStars = 1;
  bool straight = true;
  doWhileLoop(maxBlank, currentStars, maxStars, straight);
}

void printInverted(int mStar)
{
  int maxStars = mStar;
  int currentStars = maxStars - 2;
  int maxBlank = 1;
  bool straight = false;
  doWhileLoop(maxBlank, currentStars, maxStars, straight);
}

void doWhileLoop(int maxBlank, int currentStars, int maxStars, bool straight)
{
  do
  {
    printf("\n");
    printBlank(&maxBlank, straight);
    printStars(&currentStars, straight);
  } while (straight ? currentStars <= maxStars /*Straight*/ : currentStars >= 1 /*Inverted*/);
}

void printBlank(int *maxBlank, bool straight)
{
  for (int i = 0; i < *maxBlank; i++)
  {
    printf(" ");
  }
  if (straight) // true for straight
  {
    *maxBlank -= 1;
  }
  else
  {
    *maxBlank += 1; // false for inverted
  }
}

void printStars(int *maxStars, bool straight)
{
  for (int j = 1; j <= *maxStars; j++)
  {
    printf("*");
  }
  if (straight) // true for straight
  {
    *maxStars += 2;
  }
  else
  {
    *maxStars -= 2; // false for inverted
  }
}
