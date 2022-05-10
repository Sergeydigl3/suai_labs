#include "../Figures/Figures.h"
#include "FiguresList.h"

#include <iostream>
using namespace std;

void FigureList::addToHead(FigureNode* n){
    if (head!=NULL) n->setNext(head);
    head = n;
    this->size++;
}

Figure* FigureList::findFigure(int id){
    Node* currentNode = (FigureNode*)this->head;
    for (size_t i = 0; i < id; i++)
    {
        currentNode = currentNode->getNext();
    }
    return ((FigureNode* )currentNode)->getFigure();
}

void FigureList::printAll(){
    FigureNode* currentNode = (FigureNode*)this->head;
    for (size_t i = 0; i < this->size; i++)
    {
        currentNode->getFigure()->print();
        currentNode = (FigureNode*)currentNode->getNext();
        cout << endl;
    }
}
void FigureList::erase(int id){
    FigureNode* currentNode = (FigureNode*)this->head;
    for (size_t i = 0; i < this->size; i++)
    {
        currentNode->getFigure()->print();
        currentNode = (FigureNode*)currentNode->getNext();
        cout << endl;
    }
}