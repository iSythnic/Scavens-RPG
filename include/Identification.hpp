#pragma once
#include <string>

enum UniqueIDs{

};


class Identification{

    public:
    
        Identification() = delete;
        Identification(const std::string &t_Title, const unsigned int t_ID);

    public:

        std::string  m_Title;
        unsigned int m_ID;

};