#include <iostream>
#include <conio.h>
#include "Segments.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

Segment::Segment() {
    length = 0;
    for (int i = 0; i < 10; i++) {
        pointcrd[1][i] = 0;
        pointcrd[2][i] = 0;
    }
    entered = false;
}

void Segment::enterParam(int n) {
    int i, j, cnt;
    char c, s1[10];
    bool error;
    strcpy(s1, "");
    do {
        printf("Для каждой точки - %d координат(-ы).\n", n);
        for (i = 0; i < 2; i++) {
            if (i == 0)
                strcpy(s1, "начала");
            else
                strcpy(s1, "конца");
            for (j = 0; j < n; j++) {
                printf("Введите координату точки %s отрезка: ", s1);
                while (scanf("%f", &pointcrd[i][j]) != 1) {
                    printf("Введите, пожалуйста, число: ");
                    _flushall();
                }
                fflush(stdin);
            }
        }
        error = false;
        cnt = 0;
        for (i = 0; i < n - 1; i++)
            if (pointcrd[0][i] == pointcrd[0][i + 1] && pointcrd[1][i] == pointcrd[1][i + 1])
                cnt++;
        if (cnt == n - 1) {
            do {
                printf("Введенные координаты образуют одну точку и не могут служить началом и концом отрезка. "
                               "Ввести другие координаты?\n\tДа - 't';\n\tНет - 'f'.\n");
                c = getchar();
                fflush(stdin);
                c = tolower(c);
                switch (c) {
                    case 't':
                        error = true;
                        break;;
                    case 'f':
                        break;;
                }
            } while (c != 't' && c != 'f');
        }
    } while (error);
    length = 0;
    if (!entered)
        entered = true;
}

void Segment::display(int n) {
    char s2[10];
    if (entered) {
        printf("Параметры вашего отрезка:\n");
        for (int i = 0; i < 2; i++) {
            if (i == 0)
                strcpy(s2, "начала");
            else
                strcpy(s2, "конца");
            printf("\tКоординаты точки %s: ", s2);
            for (int j = 0; j < n; j++) {
                printf("%6.2f", pointcrd[i][j]);
                if (j != n - 1)
                    printf(", ");
                else
                    printf(".");
            }
            printf("\n");
        }
        if (length != 0)
            printf("\tДлина вашего отрезка: %6.2f.\n", length);
        else
            printf("Длина отрезка еще не посчитана или равна 0.\n");
    } else
        printf("Сперва введите параметры!\n");
}

void Segment::findLength(int n) {
    if (length == 0) {
        if (entered) {
            for (int i = 0; i < n; i++)
                length += sqrt((pointcrd[1][i] - pointcrd[0][i]) * (pointcrd[1][i] - pointcrd[0][i]));
            printf("Длина вашего отрезка (%6.2f) успешно посчитана.\n", length);
        } else
            printf("Сначала введите параметры!\n");
    } else
        printf("Длина отрезка уже посчитана!\n");
}

ColorSegment::ColorSegment() {
    strcpy(color, "");
}

void ColorSegment::setColor() {
    char s[100];
    bool error;
    do {
        error = false;
        printf("Введите цвет отрезка (русский язык НЕ поддерживается): ");
        if (scanf("%s", s) != 1) {
            printf("Произошла ошибка. Возможно, вы ввели русский текст!\n");
            _flushall();
            error = true;
        }
        fflush(stdin);
        if (strlen(s) > 100) {
            printf("Вы ввели слишком большой текст!\n");
            error = true;
        } else
            strcpy(color, s);
    } while (error);
}

void ColorSegment::enterParam(int n) {
    int i, j, cnt;
    char c, s3[10];
    bool error;
    setColor();
    do {
        printf("Для каждой точки - %d координат(-ы).\n", n);
        for (i = 0; i < 2; i++) {
            if (i == 0)
                strcpy(s3, "начала");
            else
                strcpy(s3, "конца");
            for (j = 0; j < n; j++) {
                printf("Введите координату точки %s отрезка: ", s3);
                while (scanf("%f", &pointcrd[i][j]) != 1) {
                    printf("Введите, пожалуйста, число: ");
                    _flushall();
                }
                fflush(stdin);
            }
        }
        error = false;
        cnt = 0;
        for (i = 0; i < n - 1; i++)
            if (pointcrd[0][i] == pointcrd[0][i + 1] && pointcrd[1][i] == pointcrd[1][i + 1])
                cnt++;
        if (cnt == n - 1) {
            printf("Введенные координаты образуют одну точку. Хотите ввести другие?\n\tДа - 't';\n\tНет - 'f'.\n"
                           "\tЕсли желаете, пользуясь случаем, изменить цвет - введите 'c';\n\t"
                           "Изменить и цвет, и координаты - 'r'.\n");
            c = getchar();
            fflush(stdin);
            c = tolower(c);
            switch (c) {
                case 't':
                    error = true;
                    break;;
                case 'f':
                    break;;
                case 'c':
                    setColor();
                    break;;
                case 'r':
                    setColor();
                    error = true;
                    break;;
                default:
                    printf("Введен неверный символ!\n");
                    break;;
            }
        }
    } while (error);
    length = 0;
    if (!entered)
        entered = true;
}

void ColorSegment::display(int n) {
    char s4[10];
    char k;
    if (entered) {
        printf("Параметры вашего отрезка:\n");
        printf("\tЦвет: %15s\n", color);
        for (int i = 0; i < 2; i++) {
            if (i == 0)
                strcpy(s4, "начала");
            else
                strcpy(s4, "конца");
            printf("\tКоординаты точки %s: ", s4);
            for (int j = 0; j < n; j++) {
                printf("%6.2f", pointcrd[i][j]);
                if (j != n - 1)
                    printf(", ");
                else
                    printf(".");
            }
            printf("\n");
        }
        if (length != 0)
            printf("\tДлина вашего отрезка: %6.2f.\n", length);
        else {
            printf("Длина отрезка еще не посчитана или равна 0. Посчитать?\n\tДа - 't'\n\tНет - 'f'.\n");
            k = getchar();
            fflush(stdin);
            k = tolower(k);
            switch (k) {
                case 't':
                    findLength(n);
                    break;;
                case 'f':
                    break;;
                default:
                    printf("Введен неверный символ!\n");
                    break;;
            }
        }
    } else {
        printf("Параметры еще не введены. Ввести сейчас?\n\tДа - 't'\n\tНет - 'f'.\n");
        k = getchar();
        fflush(stdin);
        k = tolower(k);
        if (k == 't')
            enterParam(n);
        else if (k != 'f')
            printf("Введен неверный символ!\n");
    }
}
