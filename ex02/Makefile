NAME = base

cc = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = main.cpp Base.cpp Utils.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(cc) $(CFLAGS) $(SRC) -o $(NAME)

clean :


fclean :
	rm -rf $(NAME)

re : fclean all
