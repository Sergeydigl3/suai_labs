#include <vector>
#include <string>
#include <map>
#include <ostream>

struct Node{
    std::vector<std::string> childs;
};


class Tree{
private:
    std::map<std::string, Node> tree;
    std::string root;
public:
    void addRoot(std::string& name);
    void addChild(std::string& parent, std::string& child);

    friend std::ostream& operator<<(std::ostream& os, const Tree& tree);
};

void Tree::addRoot(std::string& name){
    root = name;
    tree[name] = Node();
    tree[name].childs.push_back(name);
}

// return if parent not exist
void Tree::addChild(std::string& parent, std::string& child){
    if (tree.find(parent) == tree.end()){
        return;
    }
    tree[parent].childs.push_back(child);
}

std::ostream& operator<<(std::ostream& os, const Tree& tree){
    os << "root: " << tree.root << std::endl;
    for (auto& node : tree.tree){
        os << node.first << " : ";
        for (auto& child : node.second.childs){
            os << child << " ";
        }
        os << std::endl;
    }
    return os;
}