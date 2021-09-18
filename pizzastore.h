#ifndef PIZZASTORE_H
#define PIZZASTORE_H
#include "pizzafactory.h"
#include "stats.h"

class PizzaStore
{
public:
    PizzaFactory *Pf;


    void orderPizza(std::string type,Stats *St)
    {
        St->getPizzaType(type);
        SelectFactories();
        Pizza *pizza = Pf->SelectPizza(type);

        if (pizza != nullptr)
        {
            pizza->dough();
            pizza->prepare();
            pizza->bake();
            pizza->box();
            St->operationSuccess(true);
        }
        else
        {
            std::cout << "wrong pizza name!\n";
            St->operationSuccess(false);
        }

    }

    virtual void SelectFactories() = 0;
};

class NYPizzaStore: public PizzaStore
{
public:
    void SelectFactories()
    {
        this->Pf = new NYPizzaFactory;
    }
};

class USAPizzaStore: public PizzaStore
{
public:
    void SelectFactories()
    {
        this->Pf = new USAPizzaFactory;
    }
};

#endif // PIZZASTORE_H
