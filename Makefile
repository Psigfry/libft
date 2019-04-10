# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psigfry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 14:12:22 by psigfry           #+#    #+#              #
#    Updated: 2019/04/05 16:02:40 by psigfry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS=*.c

OBJECTS=*.o

INCLUDES=./

all: $(NAME)
	
$(NAME): $(SRCS) libft.h
		@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)

clean:
		@/bin/rm -f $(OBJECTS)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
