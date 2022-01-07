NAME = philo_bonus
SRCS = philo_bonus.c\
		life_bonus.c\
		tools_bonus.c\
		time_bonus.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus : all

%.o : %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all