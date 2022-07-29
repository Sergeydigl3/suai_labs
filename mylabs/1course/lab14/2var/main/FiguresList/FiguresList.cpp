#include "../Figures/Figures.h"
#include "FiguresList.h"

#include <iostream>
using namespace std;

void FigureList::addToHead(Figure* f){
    FigureNode* n = new FigureNode(f);
    if (head!=NULL) n->setNext(head);
    head = n;
    this->size++;
}

Figure* FigureList::findFigure(int id){
    Figure* retFigure = NULL;
    FigureNode* currentNode = (FigureNode*)this->head;
    while (currentNode)
    {
        if (currentNode->getFigure()->getId()==id){
            retFigure = ((FigureNode*)currentNode)->getFigure();
            break;
        }
        currentNode = (FigureNode*)currentNode->getNext();
    }
    
    
    return ((FigureNode* )currentNode)->getFigure();
}

void FigureList::printAll(){
    FigureNode* currentNode = (FigureNode*)this->head;
    while (currentNode)
    {
        currentNode->getFigure()->print();
        currentNode = (FigureNode*)currentNode->getNext();
        cout << endl;
    }
}
void FigureList::erase(int id){
    FigureNode* prevNode = NULL;
    FigureNode* currentNode = (FigureNode*)this->head;
    while (currentNode)
    {
        if (currentNode->getFigure()->getId()==id){
            if (currentNode->getNext()==NULL){ // check on last item
                tail = prevNode;
                tail->setNext(NULL);
            }
            if (prevNode == NULL) head = currentNode->getNext(); // check on 1-st item in list
            this->size--;
            delete currentNode;
            break;
        }
        prevNode = currentNode;
        currentNode = (FigureNode*)currentNode->getNext();
    }
}

FigureNode::FigureNode(Figure* f) { 
    this->f = f; 
};