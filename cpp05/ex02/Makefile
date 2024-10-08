# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 10:56:45 by rbutzke           #+#    #+#              #
#    Updated: 2024/10/08 10:49:31 by rbutzke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------------------------------------------------------------
# Static library
NAME		:= bureaucrat_form

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
SRC_TEST			:= src/Test/
DEBUG				:= src/Debug/
SRC_BUREAUCRAT		:= src/Bureaucrat/
SRC_AFORM			:= src/AForm/
SRC_SHRUBEERY		:= src/ShrubberyCreationForm/
SRC_ROBOTOMY		:= src/RobotomyRequestForm/
SRC_PARDON			:= src/PresidentialPardonForm/

#-----------------------------------------------------------------------------------------
# Header file includes
INCLUDES			:= -I $(SRC)\
					-I $(SRC_BUREAUCRAT)\
					-I $(SRC_AFORM)\
					-I $(SRC_SHRUBEERY)\
					-I $(SRC_ROBOTOMY)\
					-I $(SRC_PARDON)\
					-I $(COLOR)\
					-I $(DEBUG)\
					-I $(SRC_TEST)

#-----------------------------------------------------------------------------------------
# Source files
FILE_MAIN				:= main.cpp
FILE_DEGUB				:= Debug.cpp
FILE_BUREAUCRAT			:= Bureaucrat.cpp
FILE_AFORM				:= AForm.cpp
FILE_SHRUBEERY			:= ShrubberyCreationForm.cpp
FILE_ROBOTOMY			:= RobotomyRequestForm.cpp
FILE_PARDON				:= PresidentialPardonForm.cpp
FILE_TEST				:= formate_msg.cpp\
							TestManager.cpp\
							Test00.cpp Test01.cpp Test02.cpp Test03.cpp\
							Test04.cpp Test05.cpp Test06.cpp Test07.cpp\
							Test08.cpp Test09.cpp Test10.cpp Test11.cpp\
							Test12.cpp Test13.cpp Test14.cpp Test15.cpp\
							Test16.cpp Test17.cpp Test18.cpp Test19.cpp\
							Test20.cpp Test21.cpp Test22.cpp Test23.cpp\
							Test24.cpp Test25.cpp Test26.cpp\

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES	:=  $(addprefix $(SRC), $(FILE_MAIN))\
				$(addprefix $(DEBUG), $(FILE_DEGUB))\
				$(addprefix $(SRC_BUREAUCRAT), $(FILE_BUREAUCRAT))\
				$(addprefix $(SRC_AFORM), $(FILE_AFORM))\
				$(addprefix $(SRC_SHRUBEERY), $(FILE_SHRUBEERY))\
				$(addprefix $(SRC_ROBOTOMY), $(FILE_ROBOTOMY))\
				$(addprefix $(SRC_PARDON), $(FILE_PARDON))\
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
	@$(CMD_CLEAN) $(NAME) *_shrubbery

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