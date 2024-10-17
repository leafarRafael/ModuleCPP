# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2024/10/17 15:34:33 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME		:= Array

#-----------------------------------------------------------------------------------------
# Compiler and flags
CFLAGS		:= -Wall -Werror -Wextra -std=c++98 -g3
CPP			:= c++
O_FLAGS		:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN	:= rm -Rf

#-----------------------------------------------------------------------------------------
# DIRECTORY and Header file
SRC					:= src/
COLOR				:= Color/
SRC_TEST_MANAGER	:= src/Test/TestManager/
SRC_UNITTEST		:= src/Test/UnitTest/
SRC_TEST_IMPLEMENTS	:= src/Test/TestImplementation/
DEBUG				:= src/Debug/
ARRAY				:= src/Array/



#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(COLOR)\
					-I $(DEBUG)\
					-I $(SRC_TEST_MANAGER)\
					-I $(SRC_UNITTEST)\
					-I $(ARRAY)\

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_DEGUB				:= Debug.cpp
FILE_TEST_MANAGER		:= TestManager.cpp
FILE_UNITTEST			:= UnitTest.cpp
FILE_TEST				:= Test00.cpp Test01.cpp\

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(DEBUG), $(FILE_DEGUB))\
				$(addprefix $(SRC_TEST_MANAGER), $(FILE_TEST_MANAGER))\
				$(addprefix $(SRC_UNITTEST), $(FILE_UNITTEST))\
				$(addprefix $(SRC_TEST_IMPLEMENTS), $(FILE_TEST))\

#-----------------------------------------------------------------------------------------
# Directory for object files
OBJS		:= ./objs
O_FILE		:= $(SRC_FILES:%.cpp=$(OBJS)/%.o)

#-----------------------------------------------------------------------------------------
# Default rule to create the static library
all: $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to create the static library
$(NAME): $(O_FILE)
	@$(CPP) $(O_FILE) $(INCLUDES) -o $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to compile source files into object files
$(OBJS)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(INCLUDES) $(O_FLAGS) $(CFLAGS) $< -o $@

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	@$(CMD_CLEAN) $(OBJS)

fclean: clean
	@$(CMD_CLEAN) $(NAME)

re: fclean all

run:
	./$(NAME)

re_run: re
	./$(NAME)

debug: re
	./$(NAME) "DEBUG"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re