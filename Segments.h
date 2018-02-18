#include <iostream>

#ifndef SEGMENTS_H
#define SEGMENTS_H

class Segment {
protected:
    float pointcrd[2][10], segcrd[10], length;
    bool entered;
public:
    Segment();

    virtual void enterParam(int);

    virtual void display(int);

    void findLength(int);
};

class ColorSegment : public Segment {
    char color[100];
public:
    ColorSegment();

    void setColor();

    virtual void enterParam(int);

    virtual void display(int);
};

#endif
