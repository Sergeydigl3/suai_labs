#pragma once

class Node
{
protected:
    Node* next = NULL;

public:
    Node* getNext();
    void setNext(Node* node);
};


class List
{
protected:
    size_t size = 0;
    Node* head = NULL;
    Node* tail = NULL;

public:
    // List();
    void push_back(Node* n);
    size_t Size();
    ~List();
};

