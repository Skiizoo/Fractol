# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/06/20 17:11:40 by tbroggi      #+#   ##    ##    #+#        #
#    Updated: 2018/06/20 17:11:50 by tbroggi     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_putchar_fd.c \
		  ft_strchrpos.c \
		  get_next_line.c \
		  ft_putchar.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strlen.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_strlcat.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_atoi.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_itoa.c \
		  ft_strsplit.c \
		  ft_strtrim.c \
		  ft_strjoin.c \
		  ft_strsub.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strdel.c \
		  ft_strnew.c \
		  ft_memdel.c \
		  ft_memalloc.c \
		  ft_lstmap.c \
		  ft_lstiter.c \
		  ft_lstadd.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_maximum.c \
		  ft_minimum.c \
		  ft_countwords.c \
		  ft_lstrev.c \
		  ft_lstcount.c \

OBJ		= $(SRC:.c=.o)

.SILENT:

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Libft"

%.o : %.c
	gcc -Wall -Wextra -Werror -I. -c $<
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libft"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libft"

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
