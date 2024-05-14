#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 32

void change_third_byte()
{
    int number = 0;
    unsigned char third_byte;

    printf("\nEnter a number: ");
    scanf("%d", &number);

    unsigned char *ptr = (unsigned char *)&number + 2;

    printf("\nEnter the new value for the third byte: ");
    scanf("%hhu", &third_byte);

    *ptr = third_byte;

    printf("\nUpdated number:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("address = %p \t  value = %d \t i = %d \n", ptr - 2 + i, *(ptr - 2 + i), i + 1);
    }
}

void changing_code()
{
    float x = 5.0;
    printf("x = %f  ", x);

    float y = 6.0;
    printf("y = %f\n", y);

    float *xp = &x; // Only this line changed
    float *yp = &y;

    printf("Result: %f\n", *xp + *yp);
}

void array()
{
    int array_10[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *array = array_10;

    for (int i = 0; i < 10; i++)
    {
        printf("address = %p \t value = %d \t i = %d \n", (void *)(array + i), *(array + i), i);
    }
}

void substring()
{
    char str[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char *pstr;

    printf("\nEnter your string (up to %d characters):\n", MAX_LENGTH - 1);
    scanf("%s", str);

    printf("\nEnter comparison string (up to %d characters):\n", MAX_LENGTH - 1);
    scanf("%s", str2);

    pstr = strstr(str, str2);

    if (pstr == NULL)
        printf("Substring not found!\n");
    else
        printf("\nSubstring found at address: %p \nLength: %zu\n\n", (void *)pstr, strlen(str2));
}

int main()
{
    int task_num;

    printf("Select a task from 1-4: ");
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
        printf("Task number %d not found\n", task_num);
    }

    return 0;
}
