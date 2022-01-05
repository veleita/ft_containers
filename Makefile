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
CC 			= clang++
CFLAGS 		+= -Wall -Wextra -Werror -g
INCLUDES 	=	-I $(INCLUDE_DIR)utils \
				-I $(INCLUDE_DIR)iterators \
				-I $(INCLUDE_DIR)containers

# Directories ==================================================================
SRC_DIR			=	tests/
INCLUDE_DIR		=	src/
OBJ_DIR			=	obj/
STL_OBJ_DIR		=	stl/
FT_OBJ_DIR 		=	ft/

# Source files =================================================================
SRC 		=	$(shell ls $(SRC_DIR)*.cpp | cut -d '/' -f 2)
STL_OBJ 	= 	$(addprefix $(OBJ_DIR)$(STL_OBJ_DIR), $(SRC:.cpp=.o))
FT_OBJ 		= 	$(addprefix $(OBJ_DIR)$(FT_OBJ_DIR), $(SRC:.cpp=.o))



# Main targets ==================================================================
all: $(STL_TEST) $(FT_TEST)

$(STL_TEST): $(STL_OBJ)
	$(CC) $(CFLAGS) $(STL_OBJ) $(INCLUDES) -o $(STL_TEST)

$(FT_TEST): $(FT_OBJ)
	$(CC) $(CFLAGS) $(FT_OBJ) $(INCLUDES) -o $(FT_TEST)


# Creating directories ==========================================================
$(STL_OBJ_DIR):
	mkdir -p $(OBJ_DIR)$(STL_OBJ_DIR)

$(FT_OBJ_DIR):
	mkdir -p $(OBJ_DIR)$(FT_OBJ_DIR)


# Building sources ==============================================================
$(OBJ_DIR)$(STL_OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(STL_OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -D NAMESPACE=std -c $< -o $@

$(OBJ_DIR)$(FT_OBJ_DIR)%.o:	$(SRC_DIR)%.cpp | $(FT_OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -D NAMESPACE=ft -c $< -o $@



# Testing -======================================================================
original: $(STL_TEST)
	./$(STL_TEST)

replica: $(FT_TEST)
	./$(FT_TEST)

test: all
	./$(STL_TEST) > original
	./$(FT_TEST) > replica
	diff original replica
	@rm original replica


# Cleaning ======================================================================
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(FT_TEST) $(STL_TEST)

re: fclean all


.PHONY: all clean fclean re test