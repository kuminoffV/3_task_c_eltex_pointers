#include <stdio.h>
#include <sched.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 32

void change_third_byte()
{
    int number = 0, number_replace = 0, eindian = 0;
    unsigned char third_byte;

    printf("\nenter number: ");
    scanf("%d", &number);

    unsigned char *ptr = (unsigned char *)&number;

    ptr += 2;

    printf("\nnumber byte:\n");
    scanf("%hhu", &third_byte);

    *ptr = third_byte;

    ptr -= 2;

    for (int i = 0; i < 4; i++)
    {
        printf("address = %p \t  value = %d \t i = %d \n", ptr + i, *(ptr + i), i + 1);
    }
}

void changing_code()
{
    float x = 5.0;
    printf("x = %f  ", x);

    float y = 6.0;
    printf("y = %f\n", y);

    float *xp = &y;
    // float *xp = &x+1; а можно было просто сделать так)
    float *yp = &y;

    printf("Результат: %f\n", *xp + *yp);
}

void array()
{
    int array_10[10] = {
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90,
        100};
    int *array = array_10;

    for (int i = 0; i < 10; i++)
    {
        printf("address = %p \t value = %d \t i = %d \n", array + i, *(array + i), i);
    }
}

void substring()
{
    char str[32];
    char str2[32];
    char *pstr;

    while (getchar() != '\n')
        ;

    printf("\nEnter your string (up to 31 characters):\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("\nComparison string (up to 31 characters):\n");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    pstr = strstr(str, str2);

    if (pstr == NULL)
        printf("Pointer = NULL!\n");
    else
        printf("\nstrstr != 0 \nSo.Addr: %p \nMatch found in %zu symbol\n\n", (void *)pstr, strlen(str2));
}

int main()
{
    // 1. Поменять в целом положительном числе (типа int) значение
    // третьего байта на введенное пользователем число (изначальное
    // число также вводится с клавиатуры) через указатель (не применяя
    // битовые операции).

    // 2. В приведенном ниже коде измените только одну строку (помеченную),
    // чтобы напечатать “Результат: 12.0”.

    //     #include <stdio.h>
    // int main(void)
    // {
    // float x = 5.0;
    // printf("x = %f, ", x);
    // float y = 6.0;
    // printf("y = %f\n", y);
    // float *xp = &x; // TODO: отредактируйте эту строку, и только правую часть
    // уравнения
    // float *yp = &y;
    // printf("Результат: %f\n", *xp + *yp);
    // }

    // 3. Напишите программу, в которой определите массив типа int (размер
    // массива 10 элементов от 1 до 10). Используйте указатель для вывода элементов
    // массива на консоль (применять можно только арифметику указателей, а не индексы).

    // 4. Напишите программу, которая ищет введенной строке (с клавиатуры)
    // введенную подстроку (с клавиатуры) и возвращает указатель на начало
    // подстроки, если подстрока не найдена в указатель записывается NULL.
    // В качестве срок использовать статические массивы

    int task_num;

    printf("Select task from 1-4: ");
    scanf("%d", &task_num);

    switch (task_num)
    {
    case 1:
        change_third_byte();
        break;

    case 2:
        changing_code();
        break;

    case 3:
        array();
        break;
    case 4:
        substring();
        break;

    default:
        printf("Task number %u not found\n", task_num);
    }

    return 0;
}