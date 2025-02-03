# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2025/02/03 13:17:22 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME			:= PmergeMe

#-----------------------------------------------------------------------------------------
# Compiler and flags
CFLAGS			:= -Wall -Werror -Wextra -std=c++98 -g3
CPP				:= c++
O_FLAGS			:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN		:= rm -Rf

#-----------------------------------------------------------------------------------------
# DIRECTORY and Header file
SRC				:= src/
PMERGEME		:= src/PmergeMe/
INCLUDE			:= include/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(PMERGEME)\
					-I $(INCLUDE)\

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_PMERGEME			:= PmergeMe.cpp

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(PMERGEME), $(FILE_PMERGEME))\

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

re_run: re
	./$(NAME)

debug: re
	./$(NAME) "$$(shuf -i 1-3000 -n 3000 | tr '\n' ' ')"

.PHONY: all clean fclean re