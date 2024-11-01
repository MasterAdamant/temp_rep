#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>

class Singleton{
    private:
        std::stringstream text;
        std::ofstream file;

        Singleton() {
            file.open("log.txt", std::ios::app);
            text.str("");
        }
        ~Singleton(){
            file << text.rdbuf();
            file.close();
        }
    public:
        static Singleton& GetInstance(){
            static Singleton instance;
            return instance;
        }

        void Add(std::string value){
            if(!file.is_open()){
                return;
            }
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            text << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << ":" << value << '\n';
        }
};

#endif//SINGLETON_HPP