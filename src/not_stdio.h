#include <stdio.h>

int write(const void* buf, size_t count);
int put_s(const char * string);
const char * str_chr(const char * string, int target_symbol);
size_t str_len(const char * string);

int write(const void* buf, size_t count)
{
    const char * buf_pointer = (const char *) buf;
    int buf_size = count / sizeof(char);

    for (int buf_counter = 0; buf_counter < buf_size; buf_counter++, buf_pointer++)
    {
        if (putc(*buf_pointer, stdout) == EOF)
        {
            return 1;
        }
    }

    return 0;
}




