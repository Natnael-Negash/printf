#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 *
 * @format: format.
 *
 * Return: Printed chars.
 */
int _printf(const char *format, ...)

{
	int a, print = 0, print_char = 0;
	int flag, width, precision, size, buff_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lists, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{

			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print_char++;
		}
		else
		{

			print_buffer(buffer, &buff_ind);
			flags= get_flag(format, &a);
			width = get_width(format, &a, lists);
			precision = get_precision(format, &a, lists);
			size = get_size(format, &a);
			++a;
			print = handle_print(format, &a, lists, buffer,
				flag, width, precision, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(lists);

	return (print_char);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 *
 * @buffer: Array of chars
 *
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)

		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

