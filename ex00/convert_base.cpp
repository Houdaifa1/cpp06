# include "LiteralType.hpp"
# include <iomanip>
# include <cstdlib>

void char_convert(const std::string &literal)
{

    char    c = literal[0];
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);

    if (!isprint(static_cast<unsigned char>(c)))
        std::cout   << "char    : Non displayable" << std::endl;
    else
        std::cout   << "char    : " << c << std::endl;
    std::cout   << "int     : " << i << std::endl
                << std::fixed << std::setprecision(1)
                << "float   : " << f << "f" << std::endl
                << "double  : " << d << std::endl;
}

void int_convert(const std::string &literal)
{
    long value;
    value = std::strtol(literal.c_str(), NULL, 10);
    if (value >= 0 && value <= 127)
    {
        char c ;
        c = static_cast<char>(value);
        if (!isprint(static_cast<unsigned char>(c)))
            std::cout   << "char    : Non displayable" << std::endl;
        else
            std::cout   << "char    : " << c << std::endl;
    }
    else
        std::cout   << "char    : impossible" << std::endl;
    std::cout   << "int     : " << static_cast<int>(value) << std::endl
                << std::fixed << std::setprecision(1)
                << "float   : " << static_cast<float>(value) << "f" << std::endl
                << "double  : " << static_cast<double>(value) << std::endl;
    
}

void int_overflow_convert(const std::string &literal)
{
    std::cout   << "char     : impossible" << std::endl
                << "int      : impossible" << std::endl;
    float f = std::strtof(literal.c_str(), NULL);
    if (errno == ERANGE)
        std::cout << "float    : impossible"<< std::endl;
    else
        std::cout   << std::fixed << std::setprecision(1)
                    << "float    : " << f << "f" << std::endl;
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
        std::cout   << "double   : impossible"<< std::endl;
    else
        std::cout   << std::fixed << std::setprecision(1)
                    << "double   : " << d << std::endl;
}

void        float_convert(const std::string &literal)
{
    float f = std::strtof(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        std::cout   << "char     : impossible" << std::endl
                    << "int      : impossible" << std::endl
                    << "float    : impossible" << std::endl
                    << "double   : impossible\n";
        return;
    }
    if (f >= 0 && f <= 127)
    {
        char c;
        c = static_cast<char>(f);
        if (!isprint(static_cast<unsigned char>(c)))
            std::cout   << "char    : Non displayable" << std::endl;
        else
            std::cout   << "char    : " << c << std::endl;
    }
    else
        std::cout   << "char    : impossible" << std::endl;
    if (f > static_cast<float>(std::numeric_limits<int>::max()) 
        || f < static_cast<float>(std::numeric_limits<int>::min()))
        std::cout << "int      : impossible" << std::endl;
    else
        std::cout << "int      : " << static_cast<int>(f) << std::endl;
    std::cout   << std::fixed << std::setprecision(1)
                << "float    : " << f << std::endl
                << "double   : " << static_cast<double>(f) << std::endl;
}

void        double_convert(const std::string &literal)
{
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE)
    {
        std::cout   << "char     : impossible" << std::endl
                    << "int      : impossible" << std::endl
                    << "float    : impossible" << std::endl
                    << "double   : impossible\n";
        return;
    }
    if (d >= 0 && d <= 127)
    {
        char c;
        c = static_cast<char>(d);
        if (!isprint(static_cast<unsigned char>(c)))
            std::cout   << "char    : Non displayable" << std::endl;
        else
            std::cout   << "char    : " << c << std::endl;
    }
    else
        std::cout   << "char    : impossible" << std::endl;

    if (d > static_cast<double>(std::numeric_limits<int>::max()) 
        || d < static_cast<double>(std::numeric_limits<int>::min()))
        std::cout << "int      : impossible" << std::endl;
    else
        std::cout << "int      : " << static_cast<int>(d) << std::endl;

    if (d > std::numeric_limits<float>::max()
        || d < -std::numeric_limits<float>::max())
        std::cout << "float    : impossible" << std::endl;
    else
        std::cout   << std::fixed << std::setprecision(1)
                    << "float    : " << static_cast<float>(d) << std::endl;

    std::cout   << std::fixed << std::setprecision(1)
                << "double   : " << d << std::endl;
}
