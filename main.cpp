#include <iostream>
#include <stdlib.h>
#include "Segments.h"
#include <conio.h>

int main() {
    Segment seg, *segm;
    ColorSegment cseg;
    char key;
    bool b;
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
            segm->menu();
        }
    } while (key != 'q');
    delete segm;
    return 0;
}