#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>
#include <vector>

namespace read{

    int readint(std::string::iterator it, std::string& line);

    std::string readstring(std::string::iterator it, std::string& line);

    void readfile( std::string location,
                   std::vector<int>& values,
                   std::vector<std::string>& words,
                   std::vector<std::string>& files );

}

#endif