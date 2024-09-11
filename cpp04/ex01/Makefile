# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2024/09/10 17:16:39 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME		:= Brain

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
SRC_TEST			:= src/Test/
COLOR				:= Color/
BRAIN				:= src/Brain/
ANIMAL				:= src/Animal/
ANIMAL_CAT			:= src/Animal/Cat/
ANIMAL_DOG			:= src/Animal/Dog/
WRONG_ANIMAL		:= src/WrongAnimal/
WRONG_CAT			:= src/WrongAnimal/WrongCat/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(COLOR)\
					-I $(ANIMAL)\
					-I $(BRAIN)\
					-I $(ANIMAL_CAT)\
					-I $(ANIMAL_DOG)\
					-I $(WRONG_ANIMAL)\
					-I $(WRONG_CAT)\
					-I $(SRC_TEST)

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_BRAIN				:= Brain.cpp
FILE_ANIMAL				:= Animal.cpp
FILE_ANIMAL_CAT			:= Cat.cpp
FILE_ANIMAL_DOG			:= Dog.cpp
FILE_WRONG_ANIMAL		:= WrongAnimal.cpp
FILE_WRONG_CAT			:= WrongCat.cpp
FILE_TEST				:= formate_msg.cpp TestManager.cpp\
							Test00.cpp Test01.cpp\
							Test02.cpp Test03.cpp\
							Test04.cpp Test05.cpp\
							Test06.cpp Test07.cpp\
							Test08.cpp Test09.cpp

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(ANIMAL), $(FILE_ANIMAL))\
				$(addprefix $(BRAIN), $(FILE_BRAIN))\
				$(addprefix $(ANIMAL_CAT), $(FILE_ANIMAL_CAT))\
				$(addprefix $(ANIMAL_DOG), $(FILE_ANIMAL_DOG))\
				$(addprefix $(WRONG_ANIMAL), $(FILE_WRONG_ANIMAL))\
				$(addprefix $(SRC_TEST), $(FILE_TEST))\
				$(addprefix $(WRONG_CAT), $(FILE_WRONG_CAT))


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
	@$(CPP) $(O_FILE) -o $(NAME)

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

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re