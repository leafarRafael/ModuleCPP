# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2024/09/12 15:46:38 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME		:= Interface_recap

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
SRC_AMATERIA		:= src/AMateria/
SRC_MATERIA_SOURCE	:= src/MateriaSource/
SRC_CHARACTER		:= src/Character/
SRC_ICE				:= src/Ice/
SRC_CURE			:= src/Cure/
SRC_TEST			:= src/Test/
COLOR				:= Color/
DEBUG			:= src/Debug/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(SRC_AMATERIA)\
					-I $(SRC_MATERIA_SOURCE)\
					-I $(SRC_CHARACTER)\
					-I $(SRC_ICE)\
					-I $(SRC_CURE)\
					-I $(COLOR)\
					-I $(DEBUG)\
					-I $(SRC_TEST)

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_DEGUB				:= Debug.cpp
FILE_AMATERIA			:= AMateria.cpp
FILE_MATERIA_SOURCE		:= MateriaSource.cpp
FILE_CHARACTER			:= Character.cpp
FILE_ICE				:= Ice.cpp
FILE_CURE				:= Cure.cpp
FILE_TEST				:= formate_msg.cpp TestManager.cpp\
							Test00.cpp Test01.cpp\
							Test02.cpp Test03.cpp\
							Test04.cpp Test05.cpp\
							Test06.cpp

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(SRC_CHARACTER), $(FILE_CHARACTER))\
				$(addprefix $(DEBUG), $(FILE_DEGUB))\
				$(addprefix $(SRC_AMATERIA), $(FILE_AMATERIA))\
				$(addprefix $(SRC_MATERIA_SOURCE), $(FILE_MATERIA_SOURCE))\
				$(addprefix $(SRC_ICE), $(FILE_ICE))\
				$(addprefix $(SRC_CURE), $(FILE_CURE))\
				$(addprefix $(SRC_TEST), $(FILE_TEST))\



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

debug: re
	./$(NAME) "DEBUG"

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re