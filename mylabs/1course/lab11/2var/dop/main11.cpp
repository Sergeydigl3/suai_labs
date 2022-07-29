// Написать функцию void pathsplit(char *path, char *split[]) для расщепления полного пути к файлу на диск, директории, имя 
// и расширение, которые разместить в динамической памяти (malloc), а указатели на них поместить в массив указателей.
#include "lab11.h"
#include <iostream>
// #include <fstream>


#include <fstream>
#include <vector>
using namespace std;

class path_element
{
public:
    string ext = "";
    bool is_file;
    char** file;
    size_t size;

    path_element();
    path_element(char** file[], int counter, bool is_file);
    void print_path();

};

path_element::path_element(char** file[], int counter, bool is_file)
{
    if (is_file) this->ext.assign((*file)[counter - 1]);
    this->file = *file;
    this->is_file = is_file;
    this->size = counter;
}
void path_element::print_path() {
    // size_t t_size = this->is_file? this->size : this->size;
    if (this->is_file) {
        cout << file[0] << "://";
        for (size_t i = 1; i < this->size-2; i++)
        {
            cout << file[i] << "/";
        }
        cout << file[size-2] << "." << file[size-1];
    }
}

int main() {
    vector <string> allowed_ext = { "h", "cpp", "paint"};

    vector <vector <path_element>> structed_files;
    structed_files.resize(allowed_ext.size());
    ifstream file("lines.txt");
    vector <path_element> files;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            char** massive = NULL;
            const char* cstr = line.c_str();

            bool is_file = 0;
            int counter_el = 0;
            pathsplit(cstr, &massive, is_file, counter_el);
            path_element file_temp(&massive, counter_el, is_file);
            files.push_back(file_temp);
        }
        file.close();
    }

    for (size_t i = 0; i < files.size(); i++)
    {
        for (size_t ext_i = 0; ext_i < allowed_ext.size(); ext_i++)
        {
            if (files[i].ext == allowed_ext[ext_i]) structed_files[ext_i].push_back(files[i]);
        }
    }
    

    for (size_t ext_i = 0; ext_i < allowed_ext.size(); ext_i++)
    {
        if (structed_files[ext_i].size() > 0) {
            cout << "File ext: '" << allowed_ext[ext_i] << "'; Count: " << structed_files[ext_i].size() << endl;
            for (size_t i = 0; i < structed_files[ext_i].size(); i++)
            {
                structed_files[ext_i][i].print_path();
                cout<< endl;
            }

        }
        cout << endl;
    }
    return 0;
}
