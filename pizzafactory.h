#ifndef PIZZAFACTORY_H
#define PIZZAFACTORY_H
#include <iostream>
#include <string>
#include "pizza.h"

/*-------------------Pizza-------------------------------------*/
class PizzaFactory
{
public:
    virtual Pizza *SelectPizza(std::string type) = 0;
};

class NYPizzaFactory : public PizzaFactory
{
    Pizza *SelectPizza(std::string type)
    {
        Pizza *pizza = nullptr;
        if(type == "Peperoni")
             pizza = new Peperoni(new NYIngredientFactory);
        if(type == "Chicken")
             pizza = new Chicken(new NYIngredientFactory);

        return pizza;
    }
};

class USAPizzaFactory : public PizzaFactory
{
    Pizza *SelectPizza(std::string type)
    {
        Pizza *pizza = nullptr;
        if(type == "Peperoni")
             pizza = new Peperoni(new USAIngredientFactory);
        if(type == "Chicken")
             pizza = new Chicken(new USAIngredientFactory);
        return pizza;
    }
};

#endif // PIZZAFACTORY_H

