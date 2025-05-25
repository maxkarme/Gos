#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "List.h"

int main(void)
{
    char* locale = setlocale(LC_ALL, "");
    system("chcp 1251");
    List list = { 0 };

    while (1) {
        printf("Выберите операцию:\n");
        printf("1: Добавить подразделение:\n");
        printf("2: Вывести список подразделений:\n");
        printf("3: Выход:\n");

        int operation;

        printf("->");
        scanf("%d", &operation);

        if (operation == 3) break;
        if (operation == 2) {
            printList(&list);
            continue;
        }

        if (operation != 1) {
            printf("Выберите операцию от 1 до 3\n");
            continue;
        }

        Subdivision sub;
        sub.name = malloc(51 * sizeof(char));
        sub.specialization = malloc(51 * sizeof(char));
        sub.bossName = malloc(51 * sizeof(char));

        printf("Введите номер подразделения: ");
        scanf("%d", &sub.number);


        while (getchar() != '\n');
        printf("Введите Название подразделения: ");
        scanf("%[^\n]", sub.name);

        while (getchar() != '\n');
        printf("Введите Специализацию подразделения: ");
        scanf("%[^\n]", sub.specialization);

        printf("Введите Количество сотрудников: ");
        scanf("%d", &sub.countEmployes);

        while (getchar() != '\n');
        printf("Введите ФИО руководителя: ");
        scanf("%[^\n]", sub.bossName);

        add(&list, sub);
    }

    return 0;
}