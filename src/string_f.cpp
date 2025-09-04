#include "not_stdio.h"
#include <stdio.h> //!!ИСКЛЮЧИТЕЛЬНО ДЛЯ ОТЛАДКИ!!
#include <stdlib.h>

int put_s(const char * string)
{
    char symbol = * string;

    while (symbol != '\0')
    {
        if (write(&symbol, 1) != 0)
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

char * str_cpy(char* dest, const char* src)
{
    int counter = 0;
    char symbol = * src;

    while (symbol != '\0')
    {
        dest[counter] = symbol;
        counter++;
        symbol = src[counter];
    }

    dest[counter] = '\0';

    return dest;
}

char * strn_cpy(char* dest, const char* src, size_t count)
{
    size_t counter = 0;
    char symbol = * src;

    while ((symbol != '\0') && (counter < count))
    {
        dest[counter] = symbol;
        counter++;
        symbol = src[counter];
    }

    dest[counter] = '\0';

    return dest;
}

char * str_cat(char * destptr, const char * srcptr)
{
    size_t counter = 0;
    while (destptr[counter] != '\0')
    {
        counter++;
    }

    str_cpy(destptr + counter, srcptr);

    return destptr;
}

char * strn_cat(char * destptr, const char * srcptr, size_t count)
{
    size_t counter = 0;
    while (destptr[counter] != '\0')
    {
        counter++;
    }

    strn_cpy(destptr + counter, srcptr, count - counter);

    return destptr;
}

char * f_gets(char *str, int num, FILE *stream)
{
    int counter = 0;
    char character = (char) fgetc(stream);

    while (character != EOF && character != '\n' && counter < num - 1)
    {
        str[counter] = character;
        counter++;
        character = (char) fgetc(stream);
    }

    str[counter] = '\0';

    return str;
}

char * str_dup(const char * str)
{
    char * duplicate = (char *) malloc(sizeof(char) * (str_len(str) + 1));

    str_cpy(duplicate, str);

    return duplicate;
}

int main()
{
    char mas[10] = {0};
    const char * pointer = "abc";
    //проверка на пут
    put_s("abc");

    //проверка на стрчр
    printf("%p %p\n", str_chr(pointer, 'e'), pointer);

    //проверка на стрлн
    printf("%zu\n", str_len(pointer));

    //проверка на стр_копи
    strn_cpy(mas, pointer, sizeof(mas) / sizeof(mas[1]));
    printf("%s\n", mas);

    //проверка на стр_кэт
    str_cat(mas, pointer);
    printf("%s\n", mas);

    //проверка на стрн_кэт
    strn_cat(mas, pointer, sizeof(mas) / sizeof(mas[1]));
    printf("%s\n", mas);

    //проверка на фгет сэ
    f_gets(mas, 4, stdin);
    printf("%s\n", mas);

    //проверка на фгет сэ
    char * duplicate = str_dup(pointer);
    printf("%s", duplicate);
    free(duplicate);


    return 0;
}


