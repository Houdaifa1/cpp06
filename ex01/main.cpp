# include "Serializer.hpp"


int main ()
{
    Data test;
    uintptr_t raw ;

    
    test.name = "hello";
    test.x = 5;

    raw = Serializer::serialize(&test);
    
    Data *test2 = Serializer::deserialize(raw);
    
    if (test2 == &test)
        std::cout << "Same memory address\n";

    std::cout << test2->name << "   " << test2->x << std::endl;
}