# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quegonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 20:36:56 by quegonza          #+#    #+#              #
#    Updated: 2019/07/23 21:26:32 by quegonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#\/\/\/Colours

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

#\/\/\/Compiliation

NAME = fdf
CC = gcc
LFLAGS = -lX11 -lXext -lmlx
CFLAGS = -Wall -Wextra -Werror

#\/\/\/Files

SRC = q_fdf.c \

OBJ = $(SRC:.c=.o)

INC = -I ./libft/ -L ./libft -lft

#\/\/\/Rules

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(OBJ) $(INC) -o $@ $(LFLAGS)
	@echo "$(OK_COLOR)	--- FdF  created! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	$(CC) -c $(SRC)
	@echo "$(OK_COLOR)	--- " .o "   created ---	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)
clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(CLEAN_COLOR)	--- " .o "   deleted ---		$(NO_COLOR)"
	
fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- Program  deleted ---		$(NO_COLOR)"

re: fclean all
