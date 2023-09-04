SRCS	= main.cpp Base.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= identify_base

COMPILER	= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDE	= none

HEADER	= Base.hpp A.hpp B.hpp C.hpp

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp ${HEADER}
	$(COMPILER) $(FLAGS) -c $<  -o $(<:.cpp=.o)

.PHONY:	clean fclean re
