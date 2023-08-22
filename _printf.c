#include <stdarg.h>
#include <unistd.h>
#include "holberton.h"
/**
<<<<<<< HEAD
  * find_function - function that finds formats for _printf
  * calls the corresponding function.
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f find_f[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{"r", print_rev},
		{"b", print_bin},
		{"u", print_unsig},
		{"o", print_octal},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (find_f[i].sc)
	{
		if (find_f[i].sc[0] == (*format))
			return (find_f[i].f);
		i++;
	}
	return (NULL);
}
/**
  * _printf - function that produces output according to a format.
  * @format: format (char, string, int, decimal)
  * Return: size the output text;
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, cprint = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			cprint++;
			i++;
		}
		if (format[i] == '\0')
			return (cprint);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			cprint += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		cprint++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (cprint);
=======
 * _printf - prints anything
 * @format: lol
 * @...: lol
 * Return: numbers
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
	sum += print_from_to(start, p,
	params.l_modifier || params.h_modifier ? p - 1 : 0);
	else
		sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
return (sum);
>>>>>>> 38e7dcfb1cff26e0051cef7d9ebbc31af4c90789
}
