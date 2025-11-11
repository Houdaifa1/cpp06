# include "LiteralType.hpp"

void ft_remove_whitespaces(std::string& s)
{
    size_t start = 0;
    while (start < s.size() && ((s[start] >= 9 && s[start] <= 13) || s[start] == ' '))
    {
        ++start;
    }
    size_t end = s.size();
    while (end > start && ((s[end - 1] >= 9 && s[end - 1] <= 13) || s[end - 1] == ' '))
    {
        --end;
    }
    s = s.substr(start, end - start);
}

bool is_pseudo_literals(const std::string &literal, LiteralType &type)
{
    if (literal == "-inff" || literal == "+inff"
        || literal == "nanf")
    {
        type = FPSEUDO;
        return true;
    }
    if (literal == "-inf" || literal == "+inf"
        || literal == "nan")
    {
        type = DPSEUDO;
        return true;
    }
    return false;
}

bool is_char_or_int(const std::string &literal, LiteralType &type)
{
    if (literal.length() == 1)
    {
        char c = literal[0];
        if (isdigit(c))
            type = INT;
        else
            type = CHAR;
        return true;
    }
    return false;
}

bool is_int(const std::string &literal, LiteralType &type)
{
    char c;
    unsigned long long limit = 2147483647;
    unsigned long long value = 0;
    size_t i = 0;

    if (literal[i] == '-')
    {
        limit = 2147483648;
        i++;
        if (i == literal.size())
            return false;
    }
    for (size_t j = 0; j < literal.size(); j++)
    {
        char ch = literal[j];
        if (!isdigit(ch))
            return false;
    }
    while ( i < literal.size())
    {
        c = literal[i];
        int d = c - '0';
        if (value > limit / 10)
        {
            type = INTOVERFLOW;
            return true;
        }
        if (value == limit / 10 &&  (unsigned long long)d> limit % 10)
        {
            type = INTOVERFLOW;
            return true;
        }
        value = value * 10 + d;
        i++;
    }
    type = INT;
    return true;

}

bool dot_found_all_digit(const std::string &literal)
{
    int     dot_count = 0;
    size_t  dot_pos = 0;
    if (literal.size() < 3)
        return false;
    for (size_t i = 0; i < literal.size(); i++)
    {
        if (literal[i] == '.')
        {
            dot_pos = i;
            dot_count++;
        }
    }
    if (dot_count != 1 || dot_pos == 0 || dot_pos == literal.size() - 1
        || !isdigit(literal[dot_pos - 1]) || !isdigit(literal[dot_pos + 1]))
        return false;
    for(size_t j = 0; j < literal.size(); j++)
    {
        if (literal[j] == '.')
            continue;
        if(!isdigit(literal[j]))
            return false;
    }
    return true;
}

bool is_float(std::string &literal, LiteralType &type)
{
    size_t i = 0;
    if (literal[0] == '-')
    {
        if (literal.size() == 1)
            return false;
        i++;
    }
    if (literal[literal.size() - 1] != 'f')
        return false;
    std::string core = literal.substr(i, literal.size() - i - 1);
    if (!dot_found_all_digit(core))
        return false;
    type = FLOAT;
    return true;
}

bool is_double(const std::string &literal, LiteralType &type)
{
    size_t i = 0;
    if (literal[0] == '-')
    {
        if (literal.size() == 1)
            return false;
        i++;
    }
    std::string core = literal.substr(i);
    if (!dot_found_all_digit(core))
        return false;
    type = DOUBLE;
    return true;
}

LiteralType detect_type(std::string &literal)
{
    LiteralType type;

    ft_remove_whitespaces(literal);
    if (literal.empty())
        return ERROR;
    if (is_pseudo_literals(literal, type))
        return type;
    if (is_char_or_int(literal, type))
        return type;
    if (is_int(literal, type))
        return type;
    if (is_float(literal, type))
        return type;
    if (is_double(literal, type))
        return type;
    return ERROR;
}
