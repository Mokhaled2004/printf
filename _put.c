#include "main.h"

/**
* _puts - prints a string with nweline
* @str:gg
*
* Return:void
*/
int _puts(char *str)
{
char *a = str;

while (*str)
_putchar(*str++);
return (str - a);
}

/**
* _putchar - writes
* @c:gg
*
* Return: gg
* On error, -1 returned
*/
int _putchar(int c)
{
if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buf, i)
i - 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
