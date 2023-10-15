#include "main.h"
/**
* print_unsigned - Prints an unsigned number
*
* @types: Lists an of arguments.
* @buffer: buffer Arrays to handle prints.
* @flags:  calculate the active Flags.
* @width: gets Widths.
* @precision: precision specification.
* @size: size specifier
*
* Return: number of chars printed.
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int NUM = va_arg(types, unsigned long int);

NUM = convert_size_unsgnd(NUM, size);

if (NUM == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (NUM > 0)
{
buffer[a--] = (NUM % 10) + '0';
NUM /= 10;
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
* print_octal - prints an unsigned number in octal notation
*
* @types: list an of arguments
* @buffer: buffer Array to handle print
* @flags:  calculates active flags
* @width: get width
* @precision: precision specification.
* @size: size of specifier.
*
* Return: numbers of characters printed.
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int NUM = va_arg(types, unsigned long int);
unsigned long int init_num = NUM;
UNUSED(width);
NUM = convert_size_unsgnd(NUM, size);
if (NUM == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (NUM > 0)
{
buffer[a--] = (NUM % 8) + '0';
NUM /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[a--] = '0';
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal notation.
*
* @types: Lists of an arguments.
* @buffer: Buffer Array to handle print.
* @flags:  calculates active flags.
* @width:  get width.
* @precision:  precision specification.
* @size:  size specifier.
*
* Return: Number of characters printed.
*/

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));

}

/**
 * print_hexa_upper - Prints an unsigned num in upper hexadecimal notation.
 *
 * @types: Lists of an  arguments.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: size specifiers
 *
 * Return: Number of characters printed.
 */

int print_hexa_upper(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
* print_hexa -  Prints a Hexadecimal number in lower or upper.
*
* @types: Lists of an arguments
* @map_to: array of value to map the number
* @buffer: Buffer Array to handle print
* @flags:  calculate active flags
* @flag_ch: calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
* @size: Size specification
*
* Return: number of chars printed
*/
int print_hexa(va_list types, char map_to[], char buffer[],
			int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = NUM;

UNUSED(width);
num = convert_size_unsgnd(NUM, size);
if (NUM == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (NUM > 0)
{
buffer[a--] = map_to[NUM % 16];
NUM /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

