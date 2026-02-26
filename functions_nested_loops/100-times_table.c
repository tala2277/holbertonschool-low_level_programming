#include "main.h"

void print_times_table(int n)
{
        int i, j, result;

        if (n < 0 || n > 15)
                return;

        for (i = 0; i <= n; i++)
        {
                for (j = 0; j <= n; j++)
                {
                        result = i * j;

                        if (j == 0)
                        {
                                _putchar(result + '0');
                        }
                        else
                                           [ Read 40 lines ]
^G Help       ^O Write Out  ^W Where Is   ^K Cut        ^T Execute    ^C Location   M-U Undo
^X Exit       ^R Read File  ^\ Replace    ^U Paste      ^J Justify    ^/ Go To Line M-E Redo
