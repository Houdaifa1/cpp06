# ifndef LITERALTYPE_HPP
# define LITERALTYPE_HPP

# include <iostream>
# include <string>
# include <string>
# include <errno.h>
# include <limits>

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    ERROR,
    FPSEUDO,
    DPSEUDO,
    INTOVERFLOW,
};

LiteralType detect_type(std::string &literal);
void        char_convert(const std::string &literal);
void        int_convert(const std::string &literal);
void        int_overflow_convert(const std::string &literal);
void        float_convert(const std::string &literal);
void        double_convert(const std::string &literal);
void        fpseudo_convert(const std::string &literal);
void        dpseudo_convert(const std::string &literal);





# endif