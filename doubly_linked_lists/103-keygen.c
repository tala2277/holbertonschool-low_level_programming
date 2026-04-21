#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a valid key for crackme5 based on a username.
 * @argc: The number of arguments.
 * @argv: The arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
 char *username;
 char key[7];
 int len, i, res;
 char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU641omwEhe7preirSTZ";

 if (argc != 2)
  return (1);

 username = argv[1];
 len = strlen(username);

 /* Part 1 */
 key[0] = lookup[(len ^ 59) & 63];

 /* Part 2 */
 for (i = 0, res = 0; i < len; i++)
  res += username[i];
 key[1] = lookup[(res ^ 79) & 63];

 /* Part 3 */
 for (i = 0, res = 1; i < len; i++)
  res *= username[i];
 key[2] = lookup[(res ^ 85) & 63];

 /* Part 4 */
 for (res = 0, i = 0; i < len; i++)
 {
  if (username[i] > res)
   res = username[i];
 }
 srand(res ^ 14);
 key[3] = lookup[rand() & 63];

 /* Part 5 */
 for (res = 0, i = 0; i < len; i++)
  res += (username[i] * username[i]);
 key[4] = lookup[(res ^ 239) & 63];

 /* Part 6 */
 for (res = 0, i = 0; i < username[0]; i++)
  res = rand();
 key[5] = lookup[(res ^ 229) & 63];

 key[6] = '\0';
 printf("%s", key);

 return (0);
}
