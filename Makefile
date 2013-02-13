##
## Makefile for abstract in /home/goupil_r//tek2/C++/AbstractVM/repos/AbstractVM
## 
## Made by robin goupil
## Login   <goupil_r@epitech.net>
## 
## Started on  Wed Feb 13 10:48:21 2013 robin goupil
## Last update Wed Feb 13 14:27:31 2013 robin goupil
##

NAME		=	abstract

D_NAME		=	debug

SRC		=	main.cpp \
			TOperand.cpp \

C_FLAG		=	-W -Wall -Werror

D_FLAG		=	-W -Wall -Werror -g3

all:		$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) $(C_FLAG)

debug:
	g++ -o $(D_NAME) $(SRC) $(D_FLAG)

fclean:
	rm -f $(NAME) $(D_NAME)

re:		fclean $(NAME)

.PHONY:		all $(NAME) debug fclean re
