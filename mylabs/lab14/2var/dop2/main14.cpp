#include <iostream>

// #include "lab14.h"
#include "Figures/Figures.h"
#include "FiguresList/FiguresList.h"

using namespace std;
// dop Создать класс многоугольник, который задаётся массивом координат. ПРи создании нужно проверить является ли , но является пмассивом сегментов. Создать при условии, что это есть многоугольник
int main(int argc, char const *argv[])
{

    Segment Pupper1(0, 0, 0, 1);
    Segment Pupper2(0, 1, 1, 1);
    Segment Pupper3(1, 1, 0, 0);
    Segment Pupper4(4, 6, 3, 2);
    // Segment Pupper4(23, 234, 242, 32);

    FigureList flist;

    flist.addToHead(&Pupper4);
    flist.addToHead(&Pupper3);
    flist.addToHead(&Pupper2);
    flist.addToHead(&Pupper1);
    cout << endl;

    // Pupper.setSegment(49, 35);

    // cout << endl << endl << "Print list:" << endl;
    // flist.printAll();

    // flist.get(3)->print();
    Polygon Polina(&flist);
    cout << endl
         << "Exitst: " << Polina.exist() << endl
         << endl;
    // flist.findFigure(0)->print();
    return 0;
}
