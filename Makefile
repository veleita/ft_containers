# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:27:39 by mzomeno-          #+#    #+#              #
#    Updated: 2021/10/25 14:14:17 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers.exe
FT_NAME = ft_containers.exe

CC = clang++
CFLAGS += -Wall -Wextra -Werror -std=c++98 -g

INCLUDE_DIR =	include/

CONTAINERS_DIR =	containers/
SRC_FILES = 		main_original.cpp \
					test_utils.cpp \
					test_iterators.cpp \
					test_vector.cpp
SRC =				$(addprefix $(CONTAINERS_DIR), $(SRC_FILES))
OBJS =				$(SRC:.cpp=.o)

FT_CONTAINERS_DIR =	ft_containers/
FT_SRC_FILES = 		main_replica.cpp \
					test_ft_utils.cpp \
					test_ft_iterators.cpp
FT_SRC =			$(addprefix $(FT_CONTAINERS_DIR), $(FT_SRC_FILES))
FT_OBJS = 			$(FT_SRC:.cpp=.o)

all: $(NAME) $(FT_NAME)

%.o:	%.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE_DIR) -o $(NAME)

$(FT_NAME): $(FT_OBJS)
	$(CC) $(CFLAGS) $(FT_OBJS) -I $(INCLUDE_DIR) -o $(FT_NAME)


clean:
	rm -f $(OBJS) $(FT_OBJS)

fclean: clean
	rm -f $(NAME) $(FT_NAME)


re: fclean all


original: $(NAME)
	./$(NAME)

replica: $(FT_NAME)
	./$(FT_NAME)

test: re
	./$(NAME)
	./$(FT_NAME)

diff: re
	./$(NAME) > original
	./$(FT_NAME) > replica
	diff original replica
	@rm original replica

.PHONY: all clean fclean re test
