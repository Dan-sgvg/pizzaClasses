#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include "ingredientfactory.h"
#include <string>

class Pizza
{
public:
    std::string Name = "";
    IngredientFactory *If;

    virtual void setName() = 0;

    Pizza(IngredientFactory *NewIf)
    {
        this->If = NewIf;
    }

    void dough()
    {
        std::cout<< If->SelectDought(Name);
    }

    void prepare()
    {
        std::cout<< If->SelectPrepare(Name);
    }

    void bake()
    {
        std::cout<< If->SelectBake(Name);
    }

    void box()
    {
        std::cout << "boxing.\n";
    }
};

class Peperoni : public Pizza
{
public:
    Peperoni(IngredientFactory *NewIf) : Pizza(NewIf)
    {
        this->If = NewIf;
        setName();
    }

    void setName()
    {
        Name = "Peperoni";
    }
};

class Chicken : public Pizza
{
public:
    Chicken(IngredientFactory *NewIf) : Pizza(NewIf)
    {
        this->If = NewIf;
        setName();
    }
    void setName()
    {
        Name = "Chicken";
    }

};

#endif // PIZZA_H
