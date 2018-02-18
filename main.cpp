#include <iostream>
#include <stdlib.h>
#include "Segments.h"
#include <conio.h>

int main() {
    Segment seg, *segm;
    ColorSegment cseg;
    char key;
    bool b, error;
    int n;
    //setlocale(LC_ALL, "rus");
    system("chcp 65001");
    do {
        b = true;
        printf("Выберите тип отрезка:\n\t'1' - обычный отрезок;\n\t'2' - цветной отрезок.\n\t'q' - выход.\n");
        key = getchar();
        fflush(stdin);
        key = tolower(key);
        switch (key) {
            case '1':
                segm = &seg;
                break;;
            case '2':
                segm = &cseg;
                break;;
            case 'q':
                break;;
            default:
                printf("Введен неверный символ!\n");
                b = false;
                break;;
        }
        if (b && key != 'q') {
            while (key != 'b') {
                do {
                    printf("Введите размерность пространства (1, 2, 3 и т.п.): ");
                    error = false;
                    if (scanf("%d", &n) != 1) {
                        printf("Введите, пожалуйста, число!\n");
                        error = true;
                    } else if (n <= 0) {
                        printf("Размерность пространства должна быть положительной!\n");
                        error = true;
                    }
                } while (error);
                fflush(stdin);
                printf("Размерность вашего пространства: %d (%d координат(-ы) для каждой точки)."
                               "\nВы уверены?\n\tДа - 't';\n\tНет, ввести заново - 'f';"
                               "\n\tНет, вернуться назад - 'b'.\n", n, n);
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
                                segm->enterParam(n);
                                break;;
                            case 'd':
                                segm->display(n);
                                break;;
                            case 'l':
                                segm->findLength(n);
                                break;;
                            case 'b':
                                break;;
                            default:
                                printf("Введен неверный символ!\n");
                                break;;
                        }
                    }
                }
                else
                    if(key!='f' && key!='b'){
                        printf("Ошибка! Введен неверный символ!\n");
                        system("pause");
                    }
            }
        }
    } while (key != 'q');
    delete segm;
    return 0;
}