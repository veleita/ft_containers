# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:27:39 by mzomeno-          #+#    #+#              #
#    Updated: 2021/10/26 21:18:53 by mzomeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program variables ============================================================
STL_TEST 	= stl_containers
FT_TEST 	= ft_containers

# Compilation variables ========================================================
CC = clang++
CFLAGS += -Wall -Wextra -Werror -std=c++98 -g

# Directories ==================================================================
INCLUDE_DIR 	=	include/
SRC_DIR			=	tests/
STL_OBJ_DIR		=	obj/
FT_OBJ_DIR 		=	ft_obj/

# Source files =================================================================
SRC 		=	SRCS = $(shell ls $(SRC_DIR)*.cpp | cut -d '/' -f 2)
STL_OBJ 	= 	$(addprefix $(STL_OBJ_DIR), $(SRC:.cpp=.o))
FT_OBJ 		= 	$(addprefix $(FT_OBJ_DIR), $(SRC:.cpp=.o))



# Main targets ==================================================================
all: $(STL_TEST) $(FT_TEST)

$(STL_TEST): $(STL_OBJ)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE_DIR) -o $(NAME)

$(FT_TEST): $(FT_OBJ)
	$(CC) $(CFLAGS) $(FT_OBJS) -I $(INCLUDE_DIR) -o $(FT_NAME)


# Creating directories ==========================================================
$(STL_OBJ):
	mkdir $(STL_OBJ_DIR)

$(FT_OBJ):
	mkdir $(STL_OBJ_DIR)


# Building sources ==============================================================
$(STL_OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -D VERSION=stl -c $< -o $@

$(FT_OBJ_DIR)%.o:	$(SRC_DIR)%.cpp
		$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -D VERSION=ft -c $< -o $@



# Testing -======================================================================
original: $(STL_TEST)
	./$(STL_TEST)

replica: $(FT_TEST)
	./$(FT_TEST)

test: original replica

diff: all
	./$(NAME) > original
	./$(FT_NAME) > replica
	diff original replica
	@rm original replica


# Cleaning ======================================================================
clean:
	rm -f $(OBJS) $(FT_OBJS)

fclean: clean
	rm -f $(NAME) $(FT_NAME)

re: fclean all


.PHONY: all clean fclean re test