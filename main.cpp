#include <QCoreApplication>
#include <iostream>
#include <string>
#include "pizzafactory.h"
#include "PizzaStore.h"
#include "stats.h"

int main(int argc, char *argv[])
{
    std::string store; int selection; bool fileC = true;
    PizzaStore *nyps = nullptr;
    auto St = Stats::getInstance();
    QCoreApplication a(argc, argv);
    std::cout<<"1-city\n2-pizza\n3-exit\n";
    while(fileC == true)
    {
        std::cout << "Select(1-3): ";
        std::cin>>selection;
        switch(selection)
        {
            case(1):
            {
            std::cout<<"-------------------\nChoose store:\n USA \n NY\n\nSelect: ";
            std::cin >> store;
            if(store=="USA")
            {
                nyps = new USAPizzaStore;
                St->setCity("USA");
            }else

            if(store=="NY")
            {
                nyps = new NYPizzaStore;
                St->setCity("NY");
            }

            else
                {
                std::cout<<"Then USA\n";
                nyps = new USAPizzaStore;
                St->setCity("USA");
                }
            break;
            }
            case(2):
            {
                if(nyps != nullptr)
                    {
                    std::cout<<"-------------------\nChoose Pizza:\n Peperoni \n Chicken\nSelect:";
                    std::cin >> store;
                    nyps->orderPizza(store,St);
                    }
                else
                    std::cout<<"City is not selected!\n";
                break;
            }
            case(3):
            {
                St->writeToFile();
                fileC = false;
                break;
            }
        default:{
            std::cout<<"Wrong Input!\n";
            break;
        }
        }
    }
    return a.exec();
}

