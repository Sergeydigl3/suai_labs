#include "lab20.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;



Graphs::Graphs(const string& filename)
{
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        bool first_str = true;
        while (getline(file, line)) {
            if (first_str) {
                first_str = false;
                root = stoi(line);
                continue;
            }
            stringstream streamData(line);
            string val;

            const char separator = ',';
            bool first = true;
            int start_int = 0;
            while (getline(streamData, val, separator)) {
                if (first) {
                    first = false;
                    start_int = stoi(val);
                    adjacency_list[start_int];
                    continue;
                }
                adjacency_list[start_int].data.push_back(stod(val));
            }
        }
        file.close();
    }
}

ostream& operator<<(ostream& os, Graphs& gr) {

    map<int, graph_node> ::iterator it = gr.adjacency_list.begin();
    cout << "Root: " << gr.root << "\n";
    for (int i = 0; it != gr.adjacency_list.end(); it++, i++) {  // выводим их
        cout << i << ") Key " << it->first << ", value " << "{ ";
        for (size_t t = 0; t < it->second.data.size(); t++)
            cout << it->second.data[t] << ", ";
        cout << "}\n";


    }
    return os;
}

void Graphs::dfs(int cur, string& prefix) {
    adjacency_list[cur].visited = true;
    cout << prefix << " -> " << cur<< "\n";
    for (int i = 0; i < adjacency_list[cur].data.size(); i++) {
        if (adjacency_list[
            adjacency_list[cur].data[i]
        ].visited == false) {
            string new_prefix = prefix + " -> " + to_string(cur);
            dfs(adjacency_list[cur].data[i], new_prefix);
        }
    }
}