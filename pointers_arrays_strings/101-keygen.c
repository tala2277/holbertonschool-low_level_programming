#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int len = 16;

	srand((unsigned int)time(NULL));

	for (i = 0; i < len; i++)
		putchar((rand() % 94) + 33);

	putchar('\n');
	return (0);
}
