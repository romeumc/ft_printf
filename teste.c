#include <stdio.h>
#include <stdarg.h>

void
foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */

{
	va_list ap;
	int d;
	char c;
	char *s;

	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++) {
		case 's':              /* string */
			s = va_arg(ap, char *);
			//printf("string %s\n", s);
			printf("%s", s);
			break;
		case 'd':              /* int */
			d = va_arg(ap, int);
			//printf("int %d\n", d);
			printf("%d", d);
			break;
		case 'c':              /* char */
			/* need a cast here since va_arg only takes fully promoted types */
			c = (char) va_arg(ap, int);
			//printf("char %c\n", c);
			printf("%c", c);
			break;
		}
	va_end(ap);
}

int main()
{
	foo("sssdsc", "abc", "def", "hij", 12, "   ", 't');
	printf("\n");

	int width = 4;
	int num = 223;
	double simples = 111;
	double composto = 123.10; 
	double composto1 = 123.1238; 
	char romeu[] = "romeu";

	printf("decimal with * - %*d\n", width, num);
	printf("string and xX with # - %s %-s %x %#x %X %#X\n", romeu, romeu, *romeu, *romeu, *romeu, *romeu);
	printf("float - %'.2f\n", 1234567.89);
	printf("float - %'2f\n", 1234567.89);
	printf("char - %c\n", '7');
	printf("simples g - %g %#g | %0g | %-g\n", simples, simples, simples, simples);
	printf("composto g - %g %#g | %0g \n", composto, composto, composto);
	printf("composto1 g - %g %#g\n", composto1, composto1);
	printf("simples e - %e %#e\n", simples, simples);
	printf("composto e - %e %#e\n", composto, composto);
	printf("composto1 e - %e %#e\n", composto1, composto1);
}