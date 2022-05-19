#pragma once
#include "../Figures/Figures.h"
#include "../List/List.h"

class FigureNode : public Node
{
private:
    Figure* f;
public:
    Figure* getFigure() {return f;}
    FigureNode(Figure* f);

    friend class Node;
};


class FigureList : public List
{
public:
    void addToHead(Figure* n);
    Figure* findFigure(int id);
    Figure* get(int id);

    void erase(int id);
    void printAll();
};


