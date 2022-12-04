#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <time.h>
#include <filesystem>
#include "../namespaces/reader.hpp"

    void reader::wait(int seg){

        int itv = time(NULL) + seg;
        while(time(NULL) != itv){}
    }

    int reader::readint(std::string::iterator it, std::string& line){

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

    std::string reader::readstring(std::string::iterator it, std::string& line){

        std::string word = "";

        it++;

        for(it = it; it != line.end(); it++){

            if(*it == '_') break;

            else word += *it;

        }

        return word;
        
    }

    void reader::readfile( std::string location,
                   std::vector<int>& values,
                   std::vector<std::string>& words,
                   std::vector<std::string>& files ){
        
        std::fstream file;
        file.open(location, std::ios::in);

        if(file.is_open()){   

            std::string line;

            try{
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
            catch (ExcecaoArquivoInexistente &e) { std::cout << e.what();}
            file.close();
        }
    }

    void reader::readtxt(std::string location){

        //std::cout<<"             ================================"<<std::endl;

        std::fstream file;
        file.open(location, std::ios::in);

        if(file.is_open()){

            std::string line;

            while(getline(file, line)){

                if(line[0] == '#'){

                    wait(4);

                    std::cout<<std::endl;
                    std::cout<<"Pressione enter para continuar..."<<std::endl;
                    
                    char c = getchar();

                    while(c != char(10)){
                        std::cin>>c;
                        c = getchar();
                    }
                }

                else std::cout<<line<<std::endl;
            }
        }
    }
    
    ExcecaoArquivoInexistente::ExcecaoArquivoInexistente(std::string file){

        _msg = "Arquivo Inexistente: ";
        _msg += file;
        _msg += "nao existe!";

    }

    const char* ExcecaoArquivoInexistente::what() const noexcept{
        return _msg.c_str();
    }