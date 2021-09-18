#ifndef STATS_H
#define STATS_H
#include <ctime>
#include <chrono>
#include <string>
#include <fstream>
#include <mutex>
#include <iostream>

class Stats
{
private:
    Stats() {}
    std::string str = "";
    std::string city = "";
    static Stats *cf;
    static std::mutex m;

public:


    Stats(const Stats &) = delete;
    Stats &operator =(const Stats &) = delete;
    Stats(Stats &&) = delete;
    Stats &operator =(Stats &&) = delete;

    static Stats *getInstance()
     {
         std::lock_guard<std::mutex> ml(m);
         if (cf == nullptr) {
             cf = new Stats;
         }
         return cf;
     }

    void getPizzaType(std::string type){
        time_t rawtime;
        struct tm * timeinfo;
        char buffer [80];

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        strftime (buffer,80,"Time %I:%M%p",timeinfo);
        std::string s(buffer);
        str += s + " ";
        str += " City: "+ city +" Pizza type:  " + type;
    }
    void operationSuccess(bool result){
        if (result == false)
            str += "  Result: operation failed.\n";
        else
           str += "  Result: operation succes.\n";

    }
    void writeToFile(){   

        std::ofstream myfile("Pizza.txt",std::ofstream::out);
        myfile << str;
        myfile.close();
        std::cout << "end";
    }
    void setCity(std::string c)
    {
        this->city = c;
    }
};

#endif // STATS_H
