#pragma once

// create class defenition double list(classes: node, double_list) on template, functions: push_back, push_front, size, find, at(thrown exception)

#include <iostream>
#include <stdexcept>

template <typename T>
class Node
{
public:
    Node(T data, Node<T>* next = nullptr, Node<T>* prev = nullptr);
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DoubleList
{
public:
    DoubleList();
    ~DoubleList();
    void push_back(T data);
    void push_front(T data);
    int size();
    Node<T>* find(T data);
    T at(int index);
private:
    Node<T>* head;
    Node<T>* tail;
    int size_;

};
