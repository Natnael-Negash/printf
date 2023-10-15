#include "main.h"

/*
 *
 * print_char - Prints a char.
 *
 * @type: The List a of arguments.
 * @buffer: Buffer arrays to handle print.
 * @flag:  calculates active flag.
 * @width: width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],

int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)

	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
return (write(1, str, length));
}

/*
 * print_percent - Prints a percent sign
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
return (write(1, "%%", 1));
}

/*
 * print_int - Print int
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int q = va_arg(types, long int);
	unsigned long int num;

	q = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)q;

	if (q < 0)
	{
		num = (unsigned long int)((-1) * q);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, a, buffer, flags, width, precision, size));
}

/*
 * print_binary - Prints an unsigned number
 *
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of char printed.
 */
int print_binary(va_list type, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int k, h, a, sum;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	k = va_arg(types, unsigned int);
	h = 2147483648; /* (2 ^ 31) */
	b[0] = k / h;
	for (a = 1; a < 32; a++)
	{
		h /= 2;
		b[a] = (k / h) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += b[a];
		if (sum || a == 31)
		{
			char w = '0' + b[a];

			write(1, &w, 1);
			count++;
		}
	}
	return (count);
}

