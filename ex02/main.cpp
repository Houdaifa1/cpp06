# include "Utils.hpp"

int main()
{
    std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Base *ptr = generate();

        std::cout << "Pointer :   ";
        identify(ptr);

        std::cout << "Reference:   ";
        identify(*ptr);

        std::cout << "---------------------\n";
        delete ptr; 
    }

    return 0;
}