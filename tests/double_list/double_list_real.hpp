#pragma once
#include "double_list.hpp"
#include <iostream>
#include <stdexcept>

template <typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* prev)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

template <typename T>
DoubleList<T>::DoubleList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size_ = 0;
}

template <typename T>
DoubleList<T>::~DoubleList()
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoubleList<T>::push_back(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->tail = this->head;
    }
    else
    {
        this->tail->next = new Node<T>(data, nullptr, this->tail);
        this->tail = this->tail->next;
    }
    this->size_++;
}

template <typename T>
void DoubleList<T>::push_front(T data)
{
    if (this->head == nullptr)
    {
        this->head = new Node<T>(data);
        this->tail = this->head;
    }
    else
    {
        this->head->prev = new Node<T>(data, this->head, nullptr);
        this->head = this->head->prev;
    }
    this->size_++;
}

template <typename T>
int DoubleList<T>::size()
{
    return this->size_;
}

template <typename T>
Node<T>* DoubleList<T>::find(T data)
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
T DoubleList<T>::at(int index)
{
    if (index >= this->size_ || index < 0)
    {
        throw std::out_of_range("Index out of range");
    }
    Node<T>* current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}
