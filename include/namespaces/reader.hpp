#ifndef READER_H
#define READER_H

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

namespace read{

    void wait(int seg);
    
    int readint(std::string::iterator it, std::string& line);

    std::string readstring(std::string::iterator it, std::string& line);

    void readfile( std::string location,
                   std::vector<int>& values,
                   std::vector<std::string>& words,
                   std::vector<std::string>& files );

    void readtxt( std::string location);

}

#endif