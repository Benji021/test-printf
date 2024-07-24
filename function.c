#include "main.h"
#include "function.c"


int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		va_end(args);
		return (-1);
	}
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_printchar(va_arg(args, int));
					break;
				case 's':
					_printstring(va_arg(args, char*));
					break;
				case '%':
					_printchar(va_arg(args, int));
				default:
					continue;
						break;
			}
		}
		else
		{
			_printchar(*format);
		}
		format++;
	}
	va_end(args);
	return (0);
}
