#pragma once

#include <string>
// class FigureList
// {
// private:
//     /* data */
// public:
//     FigureList(/* args */);
//     void addToHead();
//     Figure findFigure(int id);
//     void erase(Figure* figure);
//     void printAll();

//     ~FigureList();
// };


class Figure
{
protected:
    int id;
public:
    int getId();
    virtual void print() = 0;
};


class Circle : public Figure {
private:
    int radius;
    std::string text;
public:
    Circle(int radius = 0, std::string text = "");
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
    Segment(int pos_start = 0, int pos_end = 0);
    void print() override;
    void setSegment(int pos_start = 0, int pos_end = 0);
    int getPosStart();
    int getPosEnd();
};
