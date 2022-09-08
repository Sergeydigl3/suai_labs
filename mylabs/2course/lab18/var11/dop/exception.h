#pragma once
#include <string>

class StoreException {
private :
    std::string m_msg;

public :
    StoreException(const std::string& msg) : m_msg(msg){};
    std::string get(){ return m_msg; };
};