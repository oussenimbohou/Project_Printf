#include <stdio.h>
#include <stdarg.h>

int _printf(char *format, ...)
{
	char *ptr;
	unsigned int i;
	va_list argument;
	char *s;

	va_start(argument, format);
	for(ptr = format; *ptr != '\0'; ptr++)
	{
		while (*ptr != '%')
		{
			putchar(*ptr);
			ptr++;
		}
		ptr++;
		switch(*ptr)
		{
			case 'c':
				i = va_arg(argument, int);
				putchar(i);
				break;
			case 's':
				s = va_arg(argument, char *);
				puts(s);
				break;
		}
	}
}

int main(void)
{
	_printf("This is my char %c, and it's from %s",'A',"Barack");
	return (0);
}
