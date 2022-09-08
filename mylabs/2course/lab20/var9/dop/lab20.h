#pragma once
#include <map>
#include <vector>
#include <ostream>
#include <string>

struct graph_node
{
    std::vector<int> data;
    bool visited;
};


class Graphs
{
private:
    std::map<int, graph_node> adjacency_list;
public:
    int root;
    Graphs(const std::string& filename);
    void dfs(int cur, std::string& prefix);


    friend std::ostream& operator<<(std::ostream& os, Graphs& gr);
};
