# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmutumbu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 20:30:00 by jmutumbu          #+#    #+#              #
#    Updated: 2025/05/13 20:30:00 by jmutumbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iincludes

SRC_DIR		= src
SRCS		= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

