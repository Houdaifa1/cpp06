# include "Utils.hpp"

Base *generate()
{
   
    int randNum = (std::rand() % 3) + 1;

    switch(randNum)
    {
        case 1:
            return new A;
        case 2:
            return new B;
        case 3:
            return new C;
    }
    return NULL;
}


void identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "the object pointed to by p: \"A\"\n";
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "the object pointed to by p: \"B\"\n";
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "the object pointed to by p: \"C\"\n";
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "the object pointed to by p: \"A\"\n";
    }
    catch (...){}
        try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "the object pointed to by p: \"B\"\n";
    }
    catch (...){}
        try
    {
        C &c =  dynamic_cast<C&>(p);
        (void)c;
        std::cout << "the object pointed to by p: \"C\"\n";
    }
    catch (...){}
}
