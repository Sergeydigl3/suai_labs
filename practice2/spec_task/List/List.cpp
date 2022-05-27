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
    n->setPrev(tail);
    tail = n;
}

size_t List::Size(){return size;}

Node::Node(uint64 x){
    this->x = x;
}

List::List(uint64 count){
    for (uint64 i = 0; i < count; i++)
    {
        this->push_back(new Node(i));
    }
}

void List::rm_first(){
    if (size==1) this->tail = NULL;
    Node *temp = this->head->getNext();
    delete this->head;
    this->head = temp;
    if (temp) temp->setPrev(NULL);
    size--;
}
void List::rm_by_node(Node* node){
    if (size<=0) return;
    if (size==1) this->tail = NULL;
    Node* n_next = node->getNext();
    Node* n_prev = node->getPrev();
    
    
    if (node == this->head)
	{
		this->head = n_next;
		if (n_next != NULL)
			n_next->setPrev(NULL);
		
	}
    else if (node == this->tail)
    {
        this->tail = n_prev;
        if (n_prev != NULL)
			n_prev->setNext(NULL);
    }
	else
	{
		n_prev->setNext(n_next);
		if (n_next != NULL)
			n_next->setPrev(n_prev);
	}
    delete node;
	this->size--;

}

uint64 List::get_first(){
    return this->head->x;
}

Node* List::get_first_node(){
    return this->head;
}

Node* Node::getNext() {
    return this->next;
}
Node* Node::getPrev() {
    return this->prev;
}

void Node::setNext(Node* node) {
    this->next = node;
}

void Node::setPrev(Node* node) {
    this->prev = node;
}


