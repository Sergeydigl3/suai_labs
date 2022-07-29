#include <iostream>
#include "Figures.h"
#include "../FiguresList/FiguresList.h"
using namespace std;

void Figure::genId()
{
    static int global_x = 0;
    this->id = global_x;
    global_x++;
}

Circle::Circle(int x, int y, int radius, std::string text)
{
    this->setPoint(x, y);
    this->radius = radius;
    this->text = text;
    genId();
}
Segment::Segment(int x, int y, int pos_start, int pos_end)
{
    this->setPoint(x, y);
    this->pos_start = pos_start;
    this->pos_end = pos_end;
    genId();
}

int Figure::getId() { return id; }

void Circle::print()
{
    cout << "Id: " << id << "\nCoord: (" << x << "; " << y << ")\nFigure: Circle\nRadius: " << radius << "\nCustom str: " << text << endl;
}
void Segment::print()
{
    cout << "Id: " << id << "\nCoord: (" << x << "; " << y << ")\nFigure: Segment\nStart pos: " << pos_start << "\nEnd pos: " << pos_end << endl;
}

void Circle::setRadius(int radius) { this->radius = radius; }
void Circle::setText(std::string text) { this->text = text; }
int Circle::getRadius() { return this->radius; }
std::string Circle::getText() { return this->text; }

void Segment::setSegment(int pos_start, int pos_end)
{
    this->pos_start = pos_start;
    this->pos_end = pos_end;
}

int Segment::getPosStart() { return pos_start; }
int Segment::getPosEnd() { return pos_end; }

int Figure::getX() { return x; }
int Figure::getY() { return y; }
void Figure::setPoint(int xc, int yc)
{
    x = xc;
    y = yc;
}

Polygon::Polygon(FigureList *l)
{
    Segment *fstSegment = (Segment *)l->get(0);
    this->setPoint(fstSegment->getX(), fstSegment->getY());
    genId();
    if (genPoly(l) == 1)
    {
        cout << "Success!" << endl;
        this->list = l;
    }
    else
        cout << "No SUCCESSO!!! MAMA MIA!!!!" << endl;
}

void Polygon::print(){};

int Polygon::genPoly(FigureList *l)
{
    // FigureNode* curr_check = (FigureNode*)l->get(i);
    if (l->Size() < 3)
    {
        cout << "Polygon should use 3+ Segments to initialization" << endl;
        return 0;
    }
    Segment *cur = (Segment *)l->get(0);
    int start_x = cur->getX();
    int start_y = cur->getY();

    int cur_x = cur->getPosStart();
    int cur_y = cur->getPosEnd();

    bool found = 0;

    int ignore_mass[l->Size()] = {0};
    ignore_mass[0] = 1;
    for (int j = 0; j < l->Size(); j++)
    {
        if (ignore_mass[j] == 1)
            continue;
        Segment *tnode = (Segment *)l->get(j);
        if (cur_x == tnode->getX() && cur_y == tnode->getY())
        {
            ignore_mass[j] = 1;
            cur_x = tnode->getPosStart();
            cur_y = tnode->getPosEnd();
            j = -1;
        }
        else if (cur_x == tnode->getPosStart() && cur_y == tnode->getPosEnd())
        {
            ignore_mass[j] = 1;
            cur_x = tnode->getX();
            cur_y = tnode->getY();
            j = -1;
        }
        if (cur_x == start_x && cur_y == start_y)
        {
            found = 1;
            break;
        }
    }
    int counter_points = 0;
    for (size_t i = 0; i < (l->Size()); i++)
        if (ignore_mass[i] == 1)
            counter_points++;

    if (counter_points == l->Size())
        return found;
    else
        cout << "Error: Foreign Segments detected" << endl;
    return 0;
}

bool Polygon::exist()
{
    return (this->list != NULL);
};
