#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for crackme5.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
 unsigned int i, res;
 size_t len;
 char *user;
 char key[7];
 char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU641omwEhe7preirSTZ";

 if (argc != 2)
  return (1);

 user = argv[1];
 len = strlen(user);

 /* 1. Based on length */
 key[0] = lookup[(len ^ 59) & 63];

 /* 2. Based on sum of chars */
 for (i = 0, res = 0; i < len; i++)
  res += user[i];
 key[1] = lookup[(res ^ 79) & 63];

 /* 3. Based on product of chars */
 for (i = 0, res = 1; i < len; i++)
  res *= user[i];
 key[2] = lookup[(res ^ 85) & 63];

 /* 4. Based on max char and randomness */
 res = 0;
 for (i = 0; i < len; i++)
  if ((unsigned int)user[i] > res)
   res = (unsigned int)user[i];
 srand(res ^ 14);
 key[3] = lookup[rand() & 63];

 /* 5. Based on sum of squares */
 res = 0;
 for (i = 0; i < len; i++)
  res += (user[i] * user[i]);
 key[4] = lookup[(res ^ 239) & 63];

 /* 6. Based on first char and loop randomness */
 res = 0;
 for (i = 0; i < (unsigned int)user[0]; i++)
  res = rand();
 key[5] = lookup[(res ^ 229) & 63];

 key[6] = '\0';
 printf("%s", key);
 return (0);
}
