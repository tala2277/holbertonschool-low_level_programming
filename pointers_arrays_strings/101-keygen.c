#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int sum = 0;
    int rand_char;

    srand(time(NULL));

    while (sum < 2772)
    {
        rand_char = rand() % 94 + 33; /* printable ASCII */

        if (sum + rand_char > 2772)
            continue;

        sum += rand_char;
        printf("%c", rand_char);
    }

    return (0);
}
