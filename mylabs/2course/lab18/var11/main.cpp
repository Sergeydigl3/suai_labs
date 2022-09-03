// 11. Реализовать класс для хранения настроек: имя настройки, значение настройки. 
//      Может быть два варианта настроек: строка---число (“color”, 34) и 
// строка-строка (“path”, “c:\labs”). 
//          add(const std::string& name, int value)
//          add(const std::string& name, const std::string& value) 
//          erase_int(const std::string &name)
//          erase_str(const std::string &name)
//          int find_int(const std::string &name)
//          std::string find_str(const std::string &name)
//          operator<< для вывода на экран
//          load(const std::string& filename) //загрузка из файла
//          save(const std::string& filename)


#include <iostream>
#include "Settings.h"
using namespace std;

// int main(int argc, char const *argv[])
// {
//     Settings sets;


//     sets.add("color1", "blue");
//     sets.add("color1", "blue");
//     sets.add("color2", "red");
//     sets.add("color3", "white");
//     sets.add("colo2r", 2);

//     cout << sets << "\n----------------------------------\nAfter Delete operation\n";

//     sets.erase_str("color2");
//     cout << sets << "\n\n----------------------------------\n";
//     cout << "Try find.\ncolor3 = " << sets.find_str("color3") << "\n";

//     sets.save("aboba.txt");
//     return 0;
// }


int main(int argc, char const *argv[])
{
    Settings sets;

    sets.load("aboba.txt");

    cout << sets << "\n\n----------------------------------\n";
    // sets.add("color1", "blue");
    // sets.add("color1", "blue");
    // sets.add("color2", "red");
    // sets.add("color3", "white");
    // sets.add("colo2r", 2);

    // cout << sets << "\n----------------------------------\nAfter Delete operation\n";

    // sets.erase_str("color2");
    // cout << sets << "\n\n----------------------------------\n";
    // cout << "Try find.\ncolor3 = " << sets.find_str("color3") << "\n";

    sets.save("aboba.txt");
    return 0;
}