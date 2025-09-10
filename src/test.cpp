#include "not_stdio.h"
#include <stdlib.h>

int main()
{
    char mas[9] = {0};
    const char * pointer = "abc";
    //проверка на пут
    put_s("abc");

    //проверка на стрчр
    printf("%p %p\n", str_chr(pointer, 'e'), pointer);

    //проверка на стрлн
    printf("%zu\n", str_len(pointer));

    //проверка на стр_копи
    strn_cpy(mas, pointer, sizeof(mas) / sizeof(mas[0]));
    printf("%s\n", mas);

    //проверка на стр_кэт
    str_cat(mas, pointer);
    printf("%s\n", mas);

    //проверка на стрн_кэт
    strn_cat(mas, pointer, sizeof(mas) / sizeof(mas[0]));
    printf("%s\n", mas);

    //проверка на фгет сэ
    f_gets(mas, 4, stdin);
    printf("%s\n", mas);

    //проверка на стр дуб
    char * duplicate = str_dup(pointer);
    printf("%s\n", duplicate);
    free(duplicate);

    size_t n = 0;
    char* lineptr;
    lineptr = NULL;
    get_line(&lineptr, &n, stdin);
    printf("%s", lineptr);
    free(lineptr);
    return 0;
}
