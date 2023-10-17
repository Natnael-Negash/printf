#include "main.h"
/**
* print_int - Print int
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width.
* @precision: Precision specification
* @size: Size specifier
* Return: Number of chars printed
*/

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
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
