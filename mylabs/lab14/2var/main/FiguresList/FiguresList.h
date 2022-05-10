#pragma once
#include "../Figures/Figures.h"
#include "../List/List.h"

class FigureNode : public Node
{
private:
    Figure* f;
public:
    Figure* getFigure() {return f;}
    FigureNode(Figure* f) { this->f = f; };

    friend class Node;
};


class FigureList : public List
{
public:
    void addToHead(FigureNode* n);
    Figure* findFigure(int id);
    void erase(int id);
    void printAll();

};


