// Array manipulation fullhouse
#include<math.h>
#include<stdbool.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include"randmagi.c"

/* Fn to fill and get array data:
min|max|sum|prod|mean|geomean|guess
-> found on init of an array
-> used indent package to format the code*/

void
introduction (int arr[], int arr_size, int yourguess)
{
  srand (time (0));
  int guess = yourguess;
  int guess_indexes[arr_size + 1];
  guess_indexes[0] = 0;
  int max_indexes[arr_size + 1];
  int min_indexes[arr_size + 1];
  int min = +666, max = -666, sum = 0, count = 0, prod = 1;
  for (int i = 0, j = 0, k = 0, m = 0; i < arr_size; i++)
    {
      arr[i] = rndmg (-100, 100);
      if (arr[i] & 1)
	count++;
      sum += arr[i];
      prod *= arr[i];
      if (arr[i] == max)
	{
	  j++;
	  max_indexes[0] = j;
	  max_indexes[j] = i;
	}
      if (arr[i] > max)
	{
	  max = arr[i];
	  j = 1;
	  max_indexes[0] = j;
	  max_indexes[1] = i;
	}
      if (arr[i] == min)
	{
	  k++;
	  min_indexes[0] = k;
	  min_indexes[k] = i;
	}
      if (arr[i] < min)
	{
	  min = arr[i];
	  k = 1;
	  min_indexes[0] = j;
	  min_indexes[1] = i;
	}
      if (arr[i] == guess)
	{
	  m++;
	  guess_indexes[0] = m;
	  guess_indexes[guess_indexes[0]] = i;
	}
    }
  printf ("\nSum is %d\tProd is %d", sum, prod);
  if (prod < 0)
    prod *= -1;
  printf ("\nmean is %.2f\
	geo|mean| is %.2f\
", sum * pow (arr_size, -1), pow (prod, pow (arr_size, -1)));
  printf ("\n%d are odd\
\t%d are even\n", count, arr_size - count);

// min-max introsection
  printf ("min is %d\tmax is %d\n", min, max);

  printf ("min in ");
  for (int i = 1; i < min_indexes[0] + 1; i++)
    {
      printf ("%d ", min_indexes[i]);
    }
  printf ("\tmax in ");
//printf ("\nmax indexes x%d:\n", max_indexes[0]);
  for (int i = 1; i < max_indexes[0] + 1; i++)
    {
      printf ("%d ", max_indexes[i]);
    }
  printf ("\n");
  printf ("min count:x%d\t", min_indexes[0]);
  printf ("max count:x%d\n", max_indexes[0]);

// guess introsection
  printf ("guess number is %d\n", guess);
  printf ("indexes x%d:\n", guess_indexes[0]);
  for (int i = 1; i < guess_indexes[0] + 1; i++)
    {
      printf ("%d ", guess_indexes[i]);
    }
  if (guess_indexes[0])
    printf ("\nLUCKY GUESS!");
  printf ("\n");
}

// A utility function to print an array
void
imprinted (int arr[], int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    {
      printf ("%d ", arr[i]);
    }
  printf ("\n");
}


/* Fn to sort and print an array using insertion*/
void
inception (int arr[], int arr_size)
{
  printf ("\nSorting w insertion...\n");
  int key, j;
  for (int i = 1; i < arr_size; i++)
    {
      key = arr[i];
      j = i - 1;
      /* Move elements of arr[0..i-1], that are
         greater than key, to one position ahead
         of their current position */
      while (j >= 0 && arr[j] > key)
	{
	  arr[j + 1] = arr[j];
	  j = j - 1;
	}
      arr[j + 1] = key;
    }
  imprinted (arr, arr_size);
void reverseArray(int arr[], int size) {
    int temp[size];
    memcpy(temp, arr, size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        arr[i] = temp[size - i - 1];
    }
}
reverseArray(arr, arr_size);
}
}
