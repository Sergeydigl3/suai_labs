#include <iostream>

// #include "lab14.h"
#include "Figures/Figures.h"
#include "FiguresList/FiguresList.h"

using namespace std;

int main(int argc, char const* argv[])
{
    Circle Suppa(0, 45, 32, "Ura pobeda ura pobeda");
    Segment Pupper(23, 234, 242, 32);


    FigureList flist;

    flist.addToHead(&Suppa);
    flist.addToHead(&Pupper);

    flist.findFigure(0)->print();
    cout << endl;

    Pupper.setSegment(49, 35);

    flist.findFigure(0)->print();

    cout << endl << endl << "Print list:" << endl;
    flist.printAll();

    flist.erase(1);
    cout << endl << endl << "Print list:" << endl;
    flist.printAll();

    cout << endl << endl;
    flist.findFigure(0)->print();
    return 0;
}
