# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 21:33:41 by mannouao          #+#    #+#              #
#    Updated: 2022/01/07 16:31:56 by mannouao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRCS = philo.c\
		check.c\
		life.c\
		tools.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
