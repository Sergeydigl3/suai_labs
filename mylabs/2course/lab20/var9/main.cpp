#include <iostream>

#include "lab20.h"

using namespace std;



int main(int argc, char const* argv[])
{
    Graphs gr("test.txt");
    cout << gr << "\n\n";
    string prefix = "";
    gr.dfs(gr.root, prefix);
    return 0;
}
