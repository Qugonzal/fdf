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
LFLAGS = -lX11 -lXext -lm
CFLAGS = -Wall -Wextra -Werror

#\/\/\/Files
SRCDIR = src
SRC = main.c $(addprefix ft_, $(addsuffix .c, \
		divers draw_segment parse_input \
		keypress iso_project))

OBJDIR = obj
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJ))

INC = -I ./inc/libft/ -L ./inc/libft -lft

MLX= /usr/include/mlx.h /usr/lib/X11/libmlx.a

#\/\/\/Rules
.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJECTS)
	@make all -C inc/libft
	$(CC) $(OBJECTS) $(INC) $(CFLAGS) $(LFLAGS) $(MLX) -o $@
	@echo "$(OK_COLOR)			+\\\\\\| FdF created! |///+	$(NO_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c inc/fdf.h Makefile
	@mkdir -p $(OBJDIR)
	@$(CC) -c $< -o $@
	@echo "$(OK_COLOR)	+++ " $@ "   created +++	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)
clean:
	@rm -rf $(OBJDIR)
	@make clean -C inc/libft
	@echo "$(CLEAN_COLOR)	--- $(NAME) object files deleted ---		$(NO_COLOR)"
	
fclean: 
	@rm -rf $(OBJDIR)
	@echo "$(CLEAN_COLOR)	--- $(NAME) object files deleted ---		$(NO_COLOR)"
	@make fclean -C inc/libft
	@rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- $(NAME)  deleted ---		$(NO_COLOR)"

re: fclean all
