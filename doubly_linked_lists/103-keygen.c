#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
 unsigned int i, sum, max_val;
 size_t len;
 char *user;
 char key[7];
 const char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU641omwEhe7preirSTZ";

 if (argc != 2)
  return (1);

 user = argv[1];
 len = strlen(user);

 /* Key index 0 */
 key[0] = lookup[(len ^ 59) & 63];

 /* Key index 1 */
 for (i = 0, sum = 0; i < len; i++)
  sum += user[i];
 key[1] = lookup[(sum ^ 79) & 63];

 /* Key index 2 */
 for (i = 0, sum = 1; i < len; i++)
  sum *= user[i];
 key[2] = lookup[(sum ^ 85) & 63];

 /* Key index 3 */
 max_val = user[0];
 for (i = 0; i < len; i++)
  if ((unsigned int)user[i] > max_val)
   max_val = user[i];
 srand(max_val ^ 14);
 key[3] = lookup[rand() & 63];

 /* Key index 4 */
 for (i = 0, sum = 0; i < len; i++)
  sum += (user[i] * user[i]);
 key[4] = lookup[(sum ^ 239) & 63];

 /* Key index 5 */
 for (i = 0, sum = 0; i < (unsigned int)user[0]; i++)
  sum = rand();
 key[5] = lookup[(sum ^ 229) & 63];

 key[6] = '\0';
 printf("%s", key);

 return (0);
}
