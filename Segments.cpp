#include <iostream>
#include <conio.h>
#include "Segments.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

Segment::Segment() {
    razm = 0;
    length = -1;
    for (int i = 0; i < 10; i++) {
        pointcrd[0][i] = 0;
        pointcrd[1][i] = 0;
    }
    entered = false;
    strcpy(s1, "");
}

int Segment::setParams() {
    int i, j, cnt;
    printf("Для каждой точки - %d координат(-ы).\n", razm);
    for (i = 0; i < 2; i++) {
        if (i == 0)
            strcpy(s1, "начала");
        else
            strcpy(s1, "конца");
        for (j = 0; j < razm; j++) {
            printf("Введите координату точки %s отрезка: ", s1);
            while (scanf("%f", &pointcrd[i][j]) != 1) {
                printf("Введите число: ");
                _flushall();
            }
            fflush(stdin);
        }
    }
    cnt = 0;
    for (i = 0; i < razm - 1; i++)
        if (pointcrd[0][i] == pointcrd[0][i + 1] && pointcrd[1][i] == pointcrd[1][i + 1])
            cnt++;
    return cnt;
}

bool Segment::getParams() {
    for (int i = 0; i < 2; i++) {
        if (i == 0)
            strcpy(s1, "начала");
        else
            strcpy(s1, "конца");
        printf("\tКоординаты точки %s: ", s1);
        for (int j = 0; j < razm; j++) {
            printf("%6.2f", pointcrd[i][j]);
            if (j != razm - 1)
                printf(", ");
            else
                printf(".");
        }
        printf("\n");
    }
    if (length != -1) {
        printf("\tДлина вашего отрезка: %6.2f.\n", length);
        return true;
    } else {
        printf("Длина отрезка еще не посчитана.\n");
        return false;
    }
}

void Segment::enterParam() {
    int i;
    char c;
    i = setParams();
    if (razm != 1) {
        while (i == razm - 1 && c != 'f') {
            printf("Введенные координаты образуют одну точку и не могут служить началом и концом отрезка. "
                           "Ввести другие координаты?\n\tДа - 't';\n\tНет - 'f'.\n");
            c = getchar();
            fflush(stdin);
            c = tolower(c);
            switch (c) {
                case 't':
                    i = setParams();
                    break;;
                case 'f':
                    break;;
                default:
                    printf("Введен неверный символ!\n");
                    break;;
            }
        }
    }
    length = -1;
    if (!entered)
        entered = true;
}

void Segment::display() {
    if (entered) {
        printf("Параметры вашего отрезка:\n");
        getParams();
    } else
        printf("Сперва введите параметры!\n");
}

void Segment::findLength() {
    if (length == -1) {
        if (entered) {
            length++;
            for (int i = 0; i < razm; i++)
                length += sqrt((pointcrd[1][i] - pointcrd[0][i]) * (pointcrd[1][i] - pointcrd[0][i]));
            printf("Длина вашего отрезка (%6.2f) успешно посчитана.\n", length);
        } else
            printf("Сначала введите параметры!\n");
    } else
        printf("Длина отрезка уже посчитана!\n");
}

void Segment::menu() {
    char key;
    bool error;
    while (key != 'b') {
        do {
            printf("Введите размерность пространства (1, 2, 3 и т.п.): ");
            error = false;
            if (scanf("%d", &razm) != 1) {
                printf("Введите число!\n");
                error = true;
            } else if (razm <= 0) {
                printf("Размерность пространства должна быть положительной!\n");
                error = true;
            } else if (razm > 10) {
                printf("Слишком большая размерность пространства!\n");
                error = true;
            }
        } while (error);
        fflush(stdin);
        printf("Размерность вашего пространства: %d (%d координат(-а/-ы) для каждой точки)."
                       "\nВы уверены?\n\tДа - 't';\n\tНет, ввести заново - 'f';"
                       "\n\tНет, вернуться назад - 'b'.\n", razm, razm);
        key = getchar();
        fflush(stdin);
        key = tolower(key);
        if (key == 't') {
            while (key != 'b') {
                printf("Введите:\n\t'e' - для ввода параметров отрезка\n\t'd' - для отображения параметров отрезка\n\t"
                               "'l' - для нахождения длины отрезка;\n\t'b' - назад.\n");
                key = getchar();
                fflush(stdin);
                key = tolower(key);
                switch (key) {
                    case 'e':
                        enterParam();
                        break;;
                    case 'd':
                        display();
                        break;;
                    case 'l':
                        findLength();
                        break;;
                    case 'b':
                        break;;
                    default:
                        printf("Введен неверный символ!\n");
                        break;;
                }
            }
        } else if (key != 'f' && key != 'b') {
            printf("Ошибка! Введен неверный символ!\n");
            system("pause");
        }
    }
    entered = false;
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

void ColorSegment::enterParam() {
    int i;
    char c;
    setColor();
    i = setParams();
    if (razm != 1) {
        while (i == razm - 1 && c != 'f' && c != 'c') {
            printf("Введенные координаты образуют одну точку. Хотите ввести другие?\n\tДа - 't';\n\tНет - 'f'.\n"
                           "\tИзменить цвет и координаты - 'r';\n\tИзменить только цвет - 'c'.\n");
            c = getchar();
            fflush(stdin);
            c = tolower(c);
            switch (c) {
                case 't':
                    i = setParams();
                    break;;
                case 'f':
                    break;;
                case 'r':
                    setColor();
                    i = setParams();
                    break;;
                case 'c':
                    setColor();
                    break;;
                default:
                    printf("Введен неверный символ!\n");
                    break;;
            }
        }
    }
    length = -1;
    if (!entered)
        entered = true;
}

void ColorSegment::display() {
    char k;
    if (entered) {
        printf("Параметры вашего отрезка:\n");
        printf("\tЦвет: %15s\n", color);
        if (!getParams()) {
            printf("Посчитать?\n\tДа - 't'\n\tНет - 'f'.\n");
            k = getchar();
            fflush(stdin);
            k = tolower(k);
            switch (k) {
                case 't':
                    findLength();
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
            enterParam();
        else if (k != 'f')
            printf("Введен неверный символ!\n");
    }
}
