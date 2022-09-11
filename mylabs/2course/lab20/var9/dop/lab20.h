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

struct logger {
    int max_depth = 0;
    std::vector<std::vector<int>> max_histories;

    friend std::ostream& operator<<(std::ostream& os, const logger& log){
        os << "Max depth: " << log.max_depth << "\n";
        os << "Max histories: \n";
        for (int i = 0; i < log.max_histories.size(); i++) {
            for (int j = 0; j < log.max_histories[i].size(); j++) {
                os << log.max_histories[i][j] << " -> ";
            }
            os << "\n";
        }
        return os;
    }
};

class Graphs
{
private:
    std::map<int, graph_node> adjacency_list;
public:
    int root;
    Graphs(const std::string& filename);
    void save(const std::string& filename);
    void save_long_path(const std::string& filename, logger& log);
    void dfs(int cur, std::string& prefix);
    void dfs_long_path(int cur, std::string& prefix, std::vector<int> history, logger& log);



    friend std::ostream& operator<<(std::ostream& os, Graphs& gr);
};
