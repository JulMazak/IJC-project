   // error.h
   // Řešení IJC-DU1, příklad b), 13.3.2021
   // Autor: Júlia Mazáková, FIT
   // Přeloženo: gcc 9.3.0
#ifndef ERROR_H
#define ERROR_H
void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);
#endif