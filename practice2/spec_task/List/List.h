#pragma once
typedef unsigned long long uint64;

class Node
{
public: 
    Node* next = NULL;
    Node* prev = NULL;

public:
    uint64 x;
    Node(uint64 x);
    Node* getNext();
    Node* getPrev();
    void setNext(Node* node);
    void setPrev(Node* node);
};


class List
{
public:
    uint64 size = 0;
    Node* head = NULL;
    Node* tail = NULL;

public:
    List(uint64 count);
    void push_back(Node* n);
    uint64 get_first();
    Node* get_first_node();
    void rm_first();
    void rm_by_node(Node* node);
    size_t Size();
    ~List();
};

