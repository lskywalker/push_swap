# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmit <lsmit@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/30 16:18:16 by lsmit         #+#    #+#                  #
#    Updated: 2021/12/06 14:07:21 by lsmit         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC_FILES	= main.c instructions.c bigstackutils.c utils.c utils2.c utils3.c calculate.c small_midsize.c ft_split.c

SRC			= $(addprefix src/, $(SRC_FILES))

OBJS		= ${SRC:.c=.o}


FLAG		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@echo "compiling $(NAME)"
	gcc -g $(FLAG) $(OBJS) -o $(NAME)

%.o: %.c
	@echo "compiling .o"
	gcc -g $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean:
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all

FORCE:

arg: all
	@./push_swap $($@) | ./checker_Mac $($@)
	@./push_swap $($@) | wc -l

##	max=500 ; export arg=`ruby -e "puts (0..$max).to_a.shuffle.join(' ')"` ; ./push_swap $arg | ./checker_Mac $arg ; ./push_swap $arg | wc -l