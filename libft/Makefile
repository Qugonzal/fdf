# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quegonza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 15:06:02 by quegonza          #+#    #+#              #
#    Updated: 2020/04/30 18:42:01 by quegonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#\/\/\/Colours
NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

NAME = libft.a

SRC =  $(addsuffix .c, $(addprefix ft_, \
	atoi		isprint		memalloc	power		putnstr		strcpy		strlcat		strnew	\
	atoli		itoa		memccpy		putchar		putstr		strcut		strlen		strnjoin\
	bzero		lstadd		memchr		putchar_fd	putstr_fd	strdel		strmap		strnstr	\
	isalnum		lstdel		memcmp		putendl		sqrt		strdup		strmapi		strrchr	\
	isalpha		lstdelone	memcpy		putendl_fd	strcat		strequ		strncat		strsplit\
	isascii		lstiter		memdel		putlongnbr	strchr		striter		strncmp		strstr	\
	isdigit		lstmap		memmove		putnbr		strclr		striteri	strncpy		strsub	\
	is_prime	lstnew		memset		putnbr_fd	strcmp		strjoin		strnequ		strtrim	\
		tolower		toupper)	\
	get_next_line)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(OK_COLOR)  + libft compiling ( ... ) + $(NO_COLOR)"
	@gcc -c $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@echo "$(OK_COLOR) ++ libft archived ++ $(NO_COLOR)"
clean:
	@rm -f $(OBJ)
	@echo "$(CLEAN_COLOR) - object files deleted: libft -$(NO_COLOR)"
fclean: 
	@rm -f $(OBJ)
	@echo "$(CLEAN_COLOR) - object files deleted: libft -$(NO_COLOR)"
	@rm -f $(NAME)
	@echo "$(CLEAN_COLOR) -- deleted: $(NAME) --$(NO_COLOR)"
re: fclean all
