#include <iostream>
#include "List.h"

using namespace std;

List::~List()
{
    Node* currentNode = this->head;
    while (currentNode)
    {
        Node* nextNode = currentNode->getNext();
        delete currentNode;
        currentNode = nextNode;
    }
}

void List::push_back(Node *n){
    if (head == NULL) head = n;
    if (tail!=NULL) this->tail->setNext(n);
    this->size++;
    tail = n;
}

size_t List::Size(){return size;}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node* node) {
    this->next = node;
}

