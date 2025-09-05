#include <stdio.h>

int write(const void* buf, size_t count);
int put_s(const char * string);
const char * str_chr(const char * string, int target_symbol);
size_t str_len(const char * string);
char * str_cpy(char* dest, const char* src);
char * strn_cpy(char* dest, const char* src, size_t count);
char * str_cat(char * destptr, const char * srcptr);
char * strn_cat(char * destptr, const char * srcptr, size_t count);
char * f_gets(char *str, int num, FILE *stream);
char * str_dup(const char *str);
ssize_t getline(char ** lineptr, size_t * n, FILE * stream);

int write(const void* buf, size_t count)
{
    const char * buf_pointer = (const char *) buf;

    for (size_t buf_counter = 0; buf_counter < count; buf_counter++, buf_pointer++)
    {
        if (putc(*buf_pointer, stdout) == EOF)
        {
            return 1;
        }
    }

    return 0;
}




