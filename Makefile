# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoreno- <smoreno-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 06:38:27 by smoreno-          #+#    #+#              #
#    Updated: 2020/02/03 23:00:32 by smoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
DIR_C = srcs
DIR_O = objs
DIR_H = incs
NAME_C = main.c \
		bintree.c \
		lexer.c \
		parser.c \
		prompt.c 
NAME_O = $(NAME_C:.c=.o)
NAME_H = twentyonesh.h \
			ast.h
FILES_C = $(addprefix $(DIR_C)/, $(NAME_C))
FILES_O = $(addprefix $(DIR_O)/, $(NAME_O))
FILES_H = $(addprefix $(DIR_H)/, $(NAME_H))
LIBFT = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(FILES_O) $(FILES_H) $(LIBFT)
#	gcc -fsanitize=address -g3 -I ./$(DIR_H) -I ./libft/ -L ./libft/ -lft -o $(NAME) $(FILES_O)
	gcc -g3 -I ./$(DIR_H) -I ./libft/ -L ./libft/ -lft -o $(NAME) $(FILES_O)
 
$(DIR_O)/%.o : $(DIR_C)/%.c $(FILES_H)
	@ mkdir -p $(DIR_O)
#	gcc -fsanitize=address -g3 -I ./$(DIR_H) $(FLAGS) -I ./libft/ -c -o $@ $<
	gcc -g3 -I ./$(DIR_H) $(FLAGS) -I ./libft/ -c -o $@ $<

$(LIBFT) :
	make -C ./libft/

.PHONY : clean
clean :
	rm -f $(FILES_O)
	make -C ./libft fclean

.PHONY : fclean
fclean : clean
	rm -f $(NAME)

.PHONY : re
re : fclean all
