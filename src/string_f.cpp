#include "not_stdio.h"
#include <stdio.h> //!!ИСКЛЮЧИТЕЛЬНО ДЛЯ ОТЛАДКИ!!

int put_s(const char * string)
{
    char symbol = * string;

    while (symbol != '\0')
    {
        if (write(&symbol, sizeof(char)) != 0)
        {
            return EOF;
        }
        string++;
        symbol = * string;
    }

    write(&"\n", sizeof(char));

    return 0;
}

const char * str_chr(const char * string, int target_symbol)
{
    const char * pointer_to_target = string;
    char symbol = * string;

    while ((symbol != target_symbol) && (symbol !='\0'))
    {
        pointer_to_target++;
        symbol = * pointer_to_target;
    }

    if (symbol != target_symbol)
    {
        return NULL;
    }

    return pointer_to_target;
}

size_t str_len(const char * string)
{
    size_t symbol_counter = 0;
    char symbol = * string;

    while (symbol != '\0')
    {
        symbol_counter++;
        string++;
        symbol = * string;
    }

    return symbol_counter;
}

int main()
{
    const char * pointer = "abc";
    //проверка на пут
    put_s("abc");
    //проверка на стрчр
    printf("%p %p\n", str_chr(pointer, 'e'), pointer);
    //проверка на стрлн
    printf("%zu", str_len(pointer));
    return 0;
}




