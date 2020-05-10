# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quegonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 20:36:56 by quegonza          #+#    #+#              #
#    Updated: 2020/05/02 19:10:54 by quegonza         ###   ########.fr        #
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
LFLAGS = -lmlx -lX11 -lXext -lm
CFLAGS = -Wall -Wextra -Werror

#\/\/\/Files
SRCDIR = src
SRC = main.c $(addsuffix .c, \
		draw_segment draw_segment_1_to_4 draw_segment_5_to_8 \
		parse_input read_and_check \
		keypress \
		keypress_moves keypress_rotate_and_switch keypress_zoom_and_depth \
		projection line_tracing)

OBJDIR = obj
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJ))

INC = -I ./libft/ -L./minilibx-linux -L ./libft -lft

MLX= ../minilibx-linux/mlx.h ../minilibx-linux/mlx_int.h

#\/\/\/Rules
.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJECTS)
	@make all -C libft
	@make all -C minilibx-linux
	$(CC) $(OBJECTS) $(INC) $(CFLAGS) $(LFLAGS) -o $@
	@echo "$(OK_COLOR)     +>| FdF successfully compiled! |<+	$(NO_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c fdf.h Makefile
	@mkdir -p $(OBJDIR)
	@$(CC) -c $< -o $@
	@echo "$(OK_COLOR)+++ compiled: " $@ " +++	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)
clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@rm -rf $(OBJDIR)
	@echo "$(CLEAN_COLOR)--- object files deleted: $(NAME) ---		$(NO_COLOR)"
	
fclean: 
	@make fclean -C libft
	@make clean -C minilibx-linux
	@rm -rf $(OBJDIR)
	@echo "$(CLEAN_COLOR)--- object files deleted: $(NAME) ---		$(NO_COLOR)"
	@rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)--- bin deleted: $(NAME) ---		$(NO_COLOR)"

re: fclean all
