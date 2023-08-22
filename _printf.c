#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{

if (*buff_ind > 0)

write(1, &buffer[0], *buff_ind);



*buff_ind = 0;

}
/**
 * _printf - prints anything
 * @format: lol
 * @...: lol
 * Return:  numbers
*/

int _printf(const char *format, ...)
{
int sum = 0;
va_list ap;
char *p, *start;
params_t params = PARAMS_INIT;
va_start(ap, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_params(&params, ap);
if (*p != '%')
{
sum += _putchar(*p);
continue;
}
start = p;
p++;
while (get_flag(p, &params))
{
p++;
}
p = get_width(p, &params, ap);
p = get_precision(p, &params, ap);
if (get_modifier(p, &params))
p++;
if (!get_specifier(p))
sum += print_from_to(start, p
, params.l_modifier || params.h_modifier ? p - 1 : 0);
else
sum += get_print_func(p, ap, &params);
}
_putchar(BUF_FLUSH);
va_end(ap);
return (sum);
}
