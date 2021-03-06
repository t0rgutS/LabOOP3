#include <iostream>

#ifndef SEGMENTS_H
#define SEGMENTS_H

class Segment {
protected:
    int razm;
    char s1[10];
    float pointcrd[2][10], length;
    bool entered;
public:
    Segment();

    void menu();

    int setParams();

    bool getParams();

    virtual void enterParam();

    virtual void display();

    void findLength();
};

class ColorSegment : public Segment {
    char color[100];
public:
    ColorSegment();

    void setColor();

    virtual void enterParam();

    virtual void display();
};

#endif
