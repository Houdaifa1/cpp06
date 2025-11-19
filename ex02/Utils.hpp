# ifndef UTILS_HPP
# define UTILS_HPP

#include <typeinfo>
# include <stdexcept>
# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);


# endif
