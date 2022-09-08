// Ориентированный граф задан и хранится списком смежности. 
// В файле задается вершина (корень), с которой начинается обход. 
// Выписать пути до каждой вершины от корня, используя алгоритм dfs.


// сгенерировать файл graphviz с обозначением самой длинной ветки
#include <iostream>

#include "lab20.h"

using namespace std;



int main(int argc, char const* argv[])
{
    // Graphs gr("test.txt");
    Graphs gr("gr.txt");

    cout << gr << "\n\n";
    string prefix = "";
    gr.dfs(gr.root, prefix);
    return 0;
}
