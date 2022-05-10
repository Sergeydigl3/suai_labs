#include <iostream>
#include "Figures.h"

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