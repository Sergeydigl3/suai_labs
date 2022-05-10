#include <iostream>

// #include "lab14.h"
#include "Figures/Figures.h"
#include "FiguresList/FiguresList.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Circle Suppa(32, "Ura pobeda ura pobeda");
    Segment Pupper(23, 32);


    FigureList flist;

    flist.addToHead(new FigureNode(&Suppa));
    flist.addToHead(new FigureNode(&Pupper));

    flist.findFigure(0)->print();
    cout<<endl;

    Pupper.setSegment(49,35);

    flist.findFigure(0)->print();

    cout << endl << endl <<"Print list:" << endl;
    flist.printAll();
    return 0;
}
