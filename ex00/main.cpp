# include "ScalarConverter.hpp"

int main (int arc, char **arv)
{
    if (arc != 2)
    {
        std::cout << "Wrong usage ./convert <argument>\n";
        return 1;
    }
    ScalarConverter::convert(arv[1]);
}