# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:27:39 by mzomeno-          #+#    #+#              #
#    Updated: 2021/10/15 18:13:49 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers
FT_NAME = ft_containers

COMPILER = clang++
CFLAGS += -Wall -Wextra -Werror -std=c++98 -g

INCLUDE_DIR =	include/

CONTAINERS_DIR =	containers/
SRC_FILES = 		main_original.cpp \
					test_utils.cpp
SRC =				$(addprefix $(CONTAINERS_DIR), $(SRC_FILES))
OBJS =				$(SRC:.cpp=.o)

FT_CONTAINERS_DIR =	ft_containers/
FT_SRC_FILES = 		main_replica.cpp \
					test_ft_utils.cpp
FT_SRC =			$(addprefix $(FT_CONTAINERS_DIR), $(SRC_FILES))
FT_OBJS = 			$(FT_SRC:.cpp=.o)

all: $(NAME)

#%.o:	%.cpp
#		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -I $(INCLUDE_DIR) -o $(NAME)

$(FT_NAME): $(FT_OBJS)
	${COMPILER} ${CFLAGS} $(FT_OBJS) -I $(INCLUDE_DIR) -o $(FT_NAME)


clean:
	rm -rf $(OBJS) $(FT_OBJS) replica original

fclean: clean
	rm -rf $(NAME) $(FT_NAME)


re: fclean all


original: $(NAME)
	./$(NAME)

replica: $(FT_NAME)
	./$(FT_NAME)

test: re

diff: re
	./$(NAME) > original
	./$(FT_NAME) > replica
	diff original replica
	@rm original replica

.PHONY: all clean fclean re test
