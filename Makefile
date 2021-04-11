# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aacquist </var/mail/aacquist>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/21 17:48:40 by aacquist          #+#    #+#              #
#    Updated: 2020/12/08 22:05:13 by aacquist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		  ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c\
		  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		  ft_lstmap.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		  ft_lstmap.c

ITEMS	= $(SRC:.c=.o)

B_ITEMS	= $(BONUS:.c=.o)

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

INC     = -I includes/


%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c $? 

all: $(NAME)

$(NAME): $(ITEMS)
	ar rc $(NAME) $(ITEMS)
	ranlib $(NAME)

clean:
	rm -f $(ITEMS) $(BONUS_ITEMS)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
	
bonus : $(NAME) $(BONUS_ITEMS) 
	ar rcs $(NAME) $(ITEMS) $(BONUS_ITEMS)

.PHONY: clean
