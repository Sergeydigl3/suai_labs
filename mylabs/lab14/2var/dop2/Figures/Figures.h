#pragma once

#include <string>
// #include "../FiguresList/FiguresList.h"


class Figure
{
protected:
    int id;
    int x;
    int y;
    void genId();
public:
    int getId();
    int getX();
    int getY();
    void setPoint(int xc, int yc);
    virtual void print() = 0;
};


class Circle : public Figure {
private:
    int radius;
    std::string text;
public:
    Circle(int x, int y, int radius = 0, std::string text = "");
    void setRadius(int radius);
    void setText(std::string text="");
    int getRadius();
    std::string getText();
    void print() override;
};

class Segment : public Figure {
private:
    int pos_start;
    int pos_end;
public:
    Segment(int x, int y, int pos_start = 0, int pos_end = 0);
    void print() override;
    void setSegment(int pos_start = 0, int pos_end = 0);
    int getPosStart();
    int getPosEnd();
};

#include "../FiguresList/FiguresList.h"
class Polygon : public Figure {
private:
    FigureList *list = NULL;
    int genPoly(FigureList *l);
public:
    Polygon(FigureList* l);
    bool exist();
    void print() override;
};
