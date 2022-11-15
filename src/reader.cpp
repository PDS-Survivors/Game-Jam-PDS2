#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <reader.hpp>


    int read::readint(std::string::iterator it, std::string& line){

        int number = 0, pot = 1;
        
        it++;

        for(it = it; it != line.end(); it++){

            if(*it == '_') break;

            else if(*it == '-') number *= -1;

            else{
                number += (int(*it) -48) * pot;
                pot *= 10;
            }

        }

        return number;
    }

    std::string read::readstring(std::string::iterator it, std::string& line){

        std::string word = "";

        it++;

        for(it = it; it != line.end(); it++){

            if(*it == '_') break;

            else word += *it;

        }

        return word;
        
    }

    void read::readfile( std::string location,
                   std::vector<int>& values,
                   std::vector<std::string>& words,
                   std::vector<std::string>& files ){
        
        std::fstream file;

        file.open(location, std::ios::in);

        if(file.is_open()){   

            std::string line;

            while(getline(file, line)){

                std::string::iterator it = line.begin();

                switch(*it){

                case 'i':
                    values.push_back(readint(it, line));
                    break;

                case 's':
                    words.push_back(readstring(it, line));
                    break;

                case 'f':
                    files.push_back(readstring(it, line));
                    break;

                default: break;

                }
            }

            
        }
    }
    