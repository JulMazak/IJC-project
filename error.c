   // error.c
   // Řešení IJC-DU1, příklad b), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	va_list arguments;
	va_start(arguments, fmt);
	vfprintf(stderr, fmt, arguments);
	va_end(arguments);
}

void error_exit(const char *fmt, ...)
{
	fprintf(stderr, "CHYBA: ");
	va_list arguments;
	va_start(arguments, fmt);
	vfprintf(stderr, fmt, arguments);
	va_end(arguments);
	exit(1);
}