#include <stdio.h>

int MyWrite(const void* buf);
int put_s(const char * string);
const char * str_chr(const char * string, int target_symbol);
size_t str_len(const char * string);
char * str_cpy(char* dest, const char* src);
char * strn_cpy(char* dest, const char* src, size_t count);
char * str_cat(char * destptr, const char * srcptr);
char * strn_cat(char * destptr, const char * srcptr, size_t count);
char * f_gets(char *str, int num, FILE *stream);
char * str_dup(const char *str);
ssize_t get_line(char ** lineptr, size_t * n, FILE * stream);
size_t power_of_ten(int n);

int MyWrite(const void* buf)
{
    const char * buf_pointer = (const char *) buf;

    if (putc(*buf_pointer, stdout) == EOF)
    {
        return 1;
    }

    return 0;
}


