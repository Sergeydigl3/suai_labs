// TASK
// 11. Сделать реализацию множества set (на основе массива с сортировкой) для хранения только уникальных элементов.
//      insert(const T& value)
//      bool find(const T& value)
//      size() возвращает количество элементов в множестве
//      set intersect(const set& s) --- пересечение (бросает исключение при пересечении с пустым множеством)
//      operator<< для вывода


// dop save load json

#include "lab17.h"
#include "iostream"
#include <string>


void do1(){

    cset<int> b11;
    cset<std::string> stri;
    stri.insert("yes");
    stri.insert("Okay");
    stri.insert("ddd");
    stri.insert("dd");
    stri.insert("d");
    stri.insert("a");
    stri.insert("ab");
    stri.insert("abc");
    stri.insert("abe");
    stri.insert("abf");
    stri.insert("aba");
    b11.insert(4);
    b11.insert(4);
    b11.insert(5);
    b11.insert(3);

    cset<int> b12(b11);
    cset<int> b13;
    b12.insert(12);
    b12.insert(11);
    cout << b11 << endl;
    cout << b12 << endl;
    stri.save_json("test.json");
    try
    {
        cout << b11.intersect(b12) << '\n';
    }
    catch(CsetException& e)
    {
        cerr << e.get() << '\n';
        throw e;
    }
    
    
    cout << b11.find(4) << endl;
    

    cout << stri << endl;

}

void do3(){
    cset<point> points_set;
    points_set.insert({15, 15, 14});
    points_set.insert({12, 15, 14});
    points_set.insert({15, 15, 14});
    points_set.insert({13, 15, 14});
    points_set.insert({15, 12, 14});
    points_set.save_json("points.json");
}

void do4(){
    cset<point> points_set;
    points_set.load_json("points.json");
    cout << points_set;
}

void do2(){
    cset<std::string> test;
    test.load_json("test.json");
    cout << test;
    // # TODO: Point Struct Check
}

int main(int argc, char const *argv[])
{
    // do1();
    // do2();
    // do3();
    do4();
    return 0;
}
// int to str

