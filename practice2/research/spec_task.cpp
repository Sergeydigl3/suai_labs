#include <iostream>
#include <math.h>
// #define N 18
// #define D 5
#include <chrono>
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
    ~List();
    void push_back(Node* n);
    uint64 get_first();
    Node* get_first_node();
    void rm_first();
    void rm_by_node(Node* node);
};



using namespace std;

uint64 count_ones(uint64 n) {
    uint64 w = 0;
    while (n > 0) {
        w += n & 1;
        n = n >> 1;
    }
    return w;
}

void List::push_back(Node* n) {
    if (head == NULL) head = n;
    if (tail != NULL) this->tail->setNext(n);
    this->size++;
    n->setPrev(tail);
    tail = n;
}

Node::Node(uint64 x) {
    this->x = x;
}

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

List::List(uint64 count) {
    for (uint64 i = 0; i < count; i++)
    {
        this->push_back(new Node(i));
    }
}

void List::rm_first() {
    if (size == 1) this->tail = NULL;
    Node* temp = this->head->getNext();
    delete this->head;
    this->head = temp;
    if (temp) temp->setPrev(NULL);
    size--;
}
void List::rm_by_node(Node* node) {
    if (size <= 0) return;
    if (size == 1) this->tail = NULL;
    Node* n_next = node->next;
    Node* n_prev = node->prev;


    if (node == this->head)
    {
        this->head = n_next;
        if (n_next != NULL)
            n_next->prev = NULL;

    }
    else if (node == this->tail)
    {
        this->tail = n_prev;
        if (n_prev != NULL)
            n_prev->next = NULL;
    }
    else
    {
        n_prev->next = n_next;
        if (n_next != NULL)
            n_next->prev = n_prev;
    }
    delete node;
    this->size--;

}

uint64 List::get_first() {
    return this->head->x;
}

Node* List::get_first_node() {
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

auto f(uint64 N, uint64 D, size_t &counter) {
    size_t M = 0; // заводим счётчик числа кодовых слов в книге
    uint64 size = pow(2, N);

    uint64 CodeBook[size] = { 0 }; // Заводим массив для списка кодовых слов с запасом.

    List fl(size);

    uint64 zero;
    Node* t_next;
    Node* curNode;
    auto t1 = chrono::high_resolution_clock::now();
    while (fl.size > 0)
    {
        // -------------------------------------------------
        zero = fl.head->x;
        CodeBook[M] = zero;
        fl.rm_first();
        M++;

        for (curNode = fl.head; curNode != NULL; curNode = t_next)
        {
            t_next = curNode->next;
            if (count_ones(curNode->x ^ CodeBook[M - 1]) < D)
                fl.rm_by_node(curNode);
        }
    }

    // cout << "Answers: ";
    // for (size_t i = 0; i < M; i++) cout << CodeBook[i] << " ";
    // cout << endl << M << end
    counter = M;
    return t1;
}

// Исходными данными программы является N - максимальная длина кода, D - минимальное расстояние кода. 
// int main()
// {
//     int ham_pairs[][2] = { {7,4}, {8,4}, {15,11}, {16,11} };
//     int count = sizeof(ham_pairs) / (sizeof(int) * 2);
//     // cout << count;
//     for (size_t i = 0; i < count; i++)
//     {

//         auto t1 = f(ham_pairs[i][0], ham_pairs[i][1]);
//         auto t2 = chrono::high_resolution_clock::now();
//         chrono::duration<float> duration = t2 - t1;
//         cout << duration.count() << endl;

//         cout << endl;
//     }

//     return 0;
// }

int main() {
    for (int d = 1; d <= 19; d++) {
            // int ham_pairs[][2] = { {7,4}, {8,4}, {15,11}, {16,11} };
            // int count = sizeof(ham_pairs) / (sizeof(int) * 2);
            // cout << count;
            cout << "d: " << d << endl;
            for (size_t n = 1; n < 19; n++)
            {
                size_t count = 0;
                auto t1 = f(n, d, count);
                auto t2 = chrono::high_resolution_clock::now();
                chrono::duration<float> duration = t2 - t1;
                // cout << duration.count() << endl;

                // cout << endl;
                cout << "N: " << n << " Time: " << duration.count() << " count: " << count << endl;
            }


    }
}