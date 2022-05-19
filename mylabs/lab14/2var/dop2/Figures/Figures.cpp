#include <iostream>
#include "Figures.h"
#include "../FiguresList/FiguresList.h"
using namespace std;

void Figure::genId() {
    static int global_x = 0;
    this->id = global_x;
    global_x++;
}

Circle::Circle(int x, int y, int radius, std::string text) {
    this->setPoint(x, y);
    this->radius = radius;
    this->text = text;
    genId();
}
Segment::Segment(int x, int y, int pos_start, int pos_end) {
    this->setPoint(x, y);
    this->pos_start = pos_start;
    this->pos_end = pos_end;
    genId();
}

int Figure::getId() { return id; }

void Circle::print() {
    cout << "Id: " << id << "\nCoord: (" << x << "; " << y << ")\nFigure: Circle\nRadius: " << radius << "\nCustom str: " << text << endl;
}
void Segment::print() {
    cout << "Id: " << id << "\nCoord: (" << x << "; " << y << ")\nFigure: Segment\nStart pos: " << pos_start << "\nEnd pos: " << pos_end << endl;
}

void Circle::setRadius(int radius) { this->radius = radius; }
void Circle::setText(std::string text) { this->text = text; }
int Circle::getRadius() { return this->radius; }
std::string Circle::getText() { return this->text; }

void Segment::setSegment(int pos_start, int pos_end) {
    this->pos_start = pos_start;
    this->pos_end = pos_end;
}

int Segment::getPosStart() { return pos_start; }
int Segment::getPosEnd() { return pos_end; }

int Figure::getX() { return x; }
int Figure::getY() { return y; }
void Figure::setPoint(int xc, int yc) { x = xc; y = yc; }

Polygon::Polygon(FigureList* l) {
    Segment* fstSegment = (Segment*)l->get(0);
    this->setPoint(fstSegment->getX(), fstSegment->getY());
    genId();
    this->list = l;
    if (genPoly(l) == 1) cout << "Success!" << endl;
    else cout << "No SUCCESSO!!! MAMA MIA!!!!" << endl;
}

void Polygon::print(){};

int Polygon::genPoly(FigureList* l) {
    // FigureNode* curr_check = (FigureNode*)l->get(i);
    Segment* cur = (Segment*)l->get(0);
    int start_x = cur->getX();
    int start_y = cur->getY();

    int cur_x = cur->getPosStart();
    int cur_y = cur->getPosEnd();

    size_t ignore_index = 0;
    
    bool found = 0;
    for (int j = 0; j < l->Size(); j++)
    {
        if (j == ignore_index) continue;
        Segment* tnode =  (Segment*)l->get(j);
        if (cur_x == start_x && cur_y == start_y) {found = 1; break;}
        if (cur_x== tnode->getX() && cur_y == tnode->getY()){
            ignore_index = j;
            cur_x = tnode->getPosStart();
            cur_y = tnode->getPosEnd();
            j = -1;
        }
        else if (cur_x== tnode->getPosStart() && cur_y == tnode->getPosEnd()){
            ignore_index = j;
            cur_x = tnode->getX();
            cur_y = tnode->getY();
            j = -1;
        }
    }
    return found;
}