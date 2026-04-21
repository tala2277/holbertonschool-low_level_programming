#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a key for crackme5.
 * @argc: The number of arguments.
 * @argv: The arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
 char key[7];
 char *lookup;
 char *username;
 int len, i, sum, prod, max, sum_sq, res_rand;

 if (argc != 2)
  return (1);

 lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";
 username = argv[1];
 for (len = 0; username[len] != '\0'; len++)
  ;

 key[0] = lookup[(len ^ 59) & 63];
 sum = 0;
 for (i = 0; i < len; i++)
  sum += username[i];
 key[1] = lookup[(sum ^ 79) & 63];
 prod = 1;
 for (i = 0; i < len; i++)
  prod *= username[i];
 key[2] = lookup[(prod ^ 85) & 63];
 max = username[0];
 for (i = 0; i < len; i++)
 {
  if (username[i] > max)
   max = username[i];
 }
 srand(max ^ 14);
 key[3] = lookup[rand() & 63];
 sum_sq = 0;
 for (i = 0; i < len; i++)
  sum_sq += (username[i] * username[i]);
 key[4] = lookup[(sum_sq ^ 239) & 63];
 for (i = 0; i < username[0]; i++)
  res_rand = rand();
 key[5] = lookup[(res_rand ^ 229) & 63];
 key[6] = '\0';
 printf("%s", key);
 return (0);
}
