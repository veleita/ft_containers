# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:27:39 by mzomeno-          #+#    #+#              #
#    Updated: 2021/10/12 17:02:44 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++
FLAGS = -Wall -Wextra -Werror -I. -std=c++98 -g

NAME = containers
FT_NAME	= ft_containers

SRCS = main_original.cpp
OBJS = $(SRCS:.cpp=.o)

FT_SRCS = main_replica.cpp
FT_OBJS = $(FT_SRCS:.cpp=.o)


all: $(NAME) $(FT_NAME)


%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	${COMPILER} ${FLAGS} $(OBJS) -o $(NAME)

$(FT_NAME): $(FT_OBJS)
	${COMPILER} ${FLAGS} $(FT_OBJS) -o $(FT_NAME)


clean:
	rm -f $(OBJS) $(FT_OBJS)

fclean: clean
	rm -f $(NAME) $(FT_NAME)


re: fclean all


test: re
	./$(NAME)
	./$(FT_NAME)

diff: re
	./$(NAME) > original
	./$(FT_NAME) > replica
	diff original replica
	@rm original replica

.PHONY: all clean fclean re test
