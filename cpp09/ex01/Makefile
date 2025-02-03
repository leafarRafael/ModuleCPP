# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2025/01/17 15:31:02 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME		:= RPN

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
DEBUG				:= src/Debug/
RPN					:= src/RPN/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(COLOR)\
					-I $(DEBUG)\
					-I $(RPN)\

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_DEGUB				:= Debug.cpp
FILE_RPN				:= RPN.cpp

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(DEBUG), $(FILE_DEGUB))\
				$(addprefix $(RPN), $(FILE_RPN))\

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

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re