// 11. Реализовать класс для хранения настроек: имя настройки, значение настройки. 
//      Может быть два варианта настроек: строка---число (“color”, 34) и строка-строка (“path”, “c:\labs”). 
        //  add(const std::string& name, int value)
        //  add(const std::string& name, const std::string& value) 
        //  erase_int(const std::string &name)
        //  erase_str(const std::string &name)
        //  int find_int(const std::string &name)
        //  std::string find_str(const std::string &name)
        //  operator<< для вывода на экран
        //  load(const std::string& filename) //загрузка из файла
        //  save(const std::string& filename)

#pragma once
#include <string>
#include "UniStore.h"
#include <ostream>

class Settings
{
private:
    UniStore<std::string> StrData;
    UniStore<int> IntData;
public:

    void add(const std::string& name, int value);
    void add(const std::string& name, const std::string& value);
    void erase_int(const std::string& name);
    void erase_str(const std::string& name);
    int find_int(const std::string& name);
    std::string find_str(const std::string& name);
    void load(const std::string& filename); //загрузка из файла
    void save(const std::string& filename);

    
    friend std::ostream& operator<<(std::ostream& os, const Settings& set);

};

