#include "main.h"

/**
 * print_char - Prints a char
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: size specifier
 *
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
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
	int len = 0, a;
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

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

return (write(1, str, len));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
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

/**
 * print_int - Print int
 *
 * @arg: arguments to print
 *
 * Return: Number of characters printed
 */
int print_int(va_list arg)
{
	int a = va_arg(arg, int);
	int num, last = a $ 10, digit, exp = 1;
	int j = 1;

	a = a / 10;
	num = a;

	if (last < 0)
	{
		_putchar('-')
			num = -num;
		a = -a;
		last = -last;
		j++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = a;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
				num = num - (digit + exp);
				exp = exp / 10;
		}
	}
	_putchar(last + '0');
	return (j);
}


/**
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

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int v, w, a, sum;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	v = va_arg(types, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	b[0] = v / w;
	for (a = 1; a < 32; a++)
	{
		w /= 2;
		b[a] = (v / w) % 2;
	}
	for (a = 0, sum = 0, count = 0; a < 32; a++)
	{
		sum += b[a];
		if (sum || a == 31)
		{
			char z = '0' + b[a];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

