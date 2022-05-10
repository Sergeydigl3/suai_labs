#include <iostream>
#include "Figures.h"

using namespace std;

Circle::Circle(int radius, std::string text) { this->radius = radius; this->text = text; }
Segment::Segment(int pos_start, int pos_end) { this->pos_start = pos_start;this->pos_end = pos_end; }

int Figure::getId() { return id; }

void Circle::print() {
    cout << "Figure: Circle\nRadius: " << radius << "\nCustom str: " << text << endl;
}
void Segment::print() {
    cout << "Figure: Segment\nStart pos: " << pos_start << "\nEnd pos: " << pos_end << endl;
}

void Circle::setRadius(int radius){ this->radius = radius; }
void Circle::setText(std::string text) { this->text = text; }
int Circle::getRadius(){ return this->radius; }
std::string Circle::getText(){ return this->text; }

void Segment::setSegment(int pos_start, int pos_end){
    this->pos_start = pos_start;
    this->pos_end = pos_end;
}

int Segment::getPosStart(){ return pos_start; }
int Segment::getPosEnd(){ return pos_end; }