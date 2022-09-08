#pragma once
#include <string>

class CsetException {
private :
    std::string m_msg;

public :
    CsetException(const std::string& msg) : m_msg(msg){};
    std::string get(){ return m_msg; };
};