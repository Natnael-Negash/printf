#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 *
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 *
 */
int print_pointer(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
char extra_C = 0, padd = ' ';
int IND = BUFF_SIZE - 2, len = 2, Padd_start = 1;
unsigned long num_addr;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addr > 0)
{
buffer[IND--] = map_to[num_addr % 16];
num_addr /= 16;
len++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_C = '+', len++;
else if (flags & F_SPACE)
extra_C = ' ', len++;
IND++;
return (write_pointer(buffer, IDN, len, width,
flags, padd, extra_C, Padd_start));
}

/**
* print_non_printable - Prints ascii codes in hexa of non printable characters.
*
* @types: List of an  argument.
* @buffer: buffer Arrays to handle prints.
* @flags:  calculates active flags
* @width: get width
* @precision: precision specification
* @size: size specifier
*
* Return: Number of characters printed
*/

int print_non_printable(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
int a = 0, OFFSET = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
return (write(1, "(null)", 6));
while (str[a] != '\0')
{
if (is_printable(str[a]))
buffer[a + OFFSET] = str[a];
else
OFFSET += append_hexa_code(str[a], buffer, a + OFFSET);
a++;
}
buffer[a + OFFSET] = '\0';
return (write(1, buffer, a + OFFSET));
}

/**
* print_reverse - Prints reverse string.
*
* @types: Lista of arguments
* @buffer: Buffer array to handle print
* @flags:  Calculates active flags
* @width: get width
* @precision: Precision specification
* @size: Size specifier
*
* Return: Numbers of chars printed
*/

int print_reverse(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
char *str;
int a, COUNT = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (a = 0; str[a]; a++)
;
for (a = a - 1; a >= 0; a--)
{
char m = str[a];
write(1, &m, 1);
COUNT++;
}
return (COUNT);
}

/**
* print_rot13string - Prints  a string in rot13.
*
* @types: Lists of an arguments
* @buffer: buffer array to handle print
* @flags:  calculates active flags
* @width: get width
* @precision: Precision specification
* @size: size specifier
*
* Return: numbers of characters printed
*/

int print_rot13string(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
char z;
char *str;
unsigned int a, b;
int COUNT = 0;
char IN[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char OUT[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
	str = "(AHYY)";
for (a = 0; str[a]; a++)
{
for (b = 0; IN[b]; b++)
{
if (IN[b] == str[a])
{
z = OUT[b];
write(1, &z, 1);
COUNT++;
break;
}
}
if (!IN[b])
{
	z = str[a];
	write(1, &z, 1);
	COUNT++;
}
}
return (COUNT);
}

