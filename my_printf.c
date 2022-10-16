#include <stdio.h>
#include <stdarg.h>

int _printf(char *format, ...)
{
	char *ptr;
	unsigned int i;
	va_list argument;
	char *s;
	int d;

	va_start(argument, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		while (*ptr != '%')
		{
			putchar(*ptr);
			ptr++;
		}
		ptr++;

		switch (*ptr)
		{
			case 'c':
				i = va_arg(argument, int);
				putchar(i);
				break;
			case 's':
				s = va_arg(argument, char *);
				puts(s);
				break;
			case 'd':
				d = va_arg(argument, int);
				putchar(d + '0');
				break;
		}
	}
}

int main(void)
{
	_printf("This is my char %c, and it's from %s, and add %d", 'A',"Barack", 9);
	return (0);
}
