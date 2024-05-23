NAME			=	philo

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror -g -pthread

LFLAGS			=	-Wall -Wextra -Werror -g -pthread

SOURCES			=	main.c \
					input_instance.c \
					input_valid_and_load.c \
					log_error_input.c \
					log_philo_die.c \
					log_philo_eat.c \
					log_philo_fork.c \
					log_philo_sleep.c \
					log_philo_think.c \
					philo_instance.c \
					philo_join.c \
					philo_life.c \
					philo_load.c \
					util_atoi.c \
					util_consume_time.c \
					util_gettime.c \
					util_isdigit.c \
					util_sleep.c

OBJS			=	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	@$(CC) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "\n\033[0;32mDone !"
	@echo -n "\033[0m"

%.o: %.c
	@printf "\033[0;33mGenerating minishell objects... %-33.33s\r" $@
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#	######