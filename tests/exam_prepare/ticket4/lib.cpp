#include <stdlib.h>


class node_t
{
private:
    int val;
    node_t* next = NULL;
public:
    node_t(int val) { this->val = val;}; // конструктор
    node_t* getNext(){return this->next;}
    int getVal(){return val;}
};

class list_t
{
private:
    node_t* head;
    size_t size;
public:
    list_t();
    list_t(list_t& l);
    list_t& operator=(list_t& v);
    ~list_t();
};
list_t::list_t(){ size=0; head=NULL; } // конструктор
list_t::list_t(list_t& l){ // конструктор копий
    size = l.size;
    node_t *f_cur = l.head;
    node_t *cur = NULL;
    if (f_cur!=NULL){
        cur = new node_t(f_cur->getVal());
        head = cur; f_cur = f_cur->getNext();
    }
    while (f_cur!=NULL){
        cur = new node_t(f_cur->getVal());
        f_cur = f_cur->getNext();
    }
}
list_t& list_t::operator=(list_t& l){
    if (&l == this) return *this;
    this->~list_t();
    // тут тот же код что и в конструкторе копий
    return *this;
}
list_t::~list_t() // деструктор
{
    node_t * cur = this->head;
    while (cur!=NULL)
    {
        node_t *temp = cur;
        cur = cur->getNext();
        delete temp;
    }
    head = NULL; size=0;
}


