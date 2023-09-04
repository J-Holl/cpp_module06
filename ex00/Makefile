SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= convert

COMPILER	= c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

INCLUDE	= none

HEADER	=

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
