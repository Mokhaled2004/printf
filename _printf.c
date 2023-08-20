#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: gg.
 * Return: gg.
 */
int _printf(const char *format, ...)
{
int i = 0;
int print = 0;
int printedchars = 0;
int flags = 0;
int width = 0;
int precision = 0;
int size = 0;
int buffend = 0;
    
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buffend++] = format[i];
if (buffend == BUFF_SIZE)
print_buffer(buffer, &buffend);
printedchars++;
}
else
{
print_buffer(buffer, &buffend);
flags = get_flags(format, &i);
width = get_width(format, &i, list);
precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
print = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (print == -1)
return (-1);
printedchars += print;
}
}

print_buffer(buffer, &buffend);
va_end(list);
return (printedchars);
}

/**
 * print_buffer - Prints contents of buffer if exists
 * @buffer: gg
 * @buff_ind: easy.
 */
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}


