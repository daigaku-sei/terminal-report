// coded in Termux, tested with clang
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include"ar_reli.c"


int
main (int args, char *argv[])
{
  printf("______\n");
  printf("\n c1: [9] => T3,I3,M1: array operations on [N]x1 of random int\n");
  printf("______");

  srand (time (0));
  printf ("\nTry to guess rnd number, \
that will be generated by this program...\nGuess number is ?=");
  int guess_number;
  int validGuess = 0;
  while (!validGuess) {
      printf("Enter a number to search: ");
      if (scanf("%d", &guess_number) == 1) {
          printf("Guess is acknowledged!\n");
          validGuess = 1;
      }
      else {
          printf("No valid int - please try again.\n");
          // Clear the input buffer
          int c;
          while ((c = getchar()) != '\n' && c != EOF) {}
      }
  }
  printf ("%d", guess_number);
  printf ("\nThe size of an array is randomed!");
  int size = rndmg (5, 20);
  int matrix[size];
  introduction (matrix, size, guess_number);
  imprinted (matrix, size);
  inception (matrix, size);

  int exitLoop = 0;
  while (!exitLoop) {
      int numinor;
      printf("Enter a number to search (enter 666 to exit): ");
      if (scanf("%d", &numinor) == 1) {
          if (numinor == 666) {
              exitLoop = 1;
          }
          searchArray(matrix, size, numinor);
      }
      else {
          printf("No valid int - please try again.\n");
          // Clear the input buffer
          int c;
          while ((c = getchar()) != '\n' && c != EOF) {}
      }
  }

  return 0;
}
