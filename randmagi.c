// C program for generating a
// random number in a given range
#include<stdlib.h>
int
rndmg (int lower, int upper)
{
  int num = (rand () % (upper - lower + 1)) + lower;
  return num;
}
