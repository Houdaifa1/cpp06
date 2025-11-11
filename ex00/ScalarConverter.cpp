# include "ScalarConverter.hpp"
# include "LiteralType.hpp"


void ScalarConverter::convert(std::string literal)
{
    LiteralType type = detect_type(literal);
    std::cout << "type : " << type << "\n\n";
    switch (type)
    {
        case CHAR :
            char_convert(literal);
            break;
        case INT:
            int_convert(literal);
            break;
        case INTOVERFLOW:
            int_overflow_convert(literal);
            break;
        case FLOAT:
            float_convert(literal);
            break;
        case DOUBLE:
            float_convert(literal);
            break;
        default:
            std::cout << "Error!! It shoud be char or int or float or double\n";
            break;
    }
    



}