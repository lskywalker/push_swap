# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmit <lsmit@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/30 16:18:16 by lsmit         #+#    #+#                  #
#    Updated: 2021/09/17 14:10:45 by lsmit         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRC_FILES	= main.c instructions.c

SRC			= $(addprefix src/, $(SRC_FILES))

OBJS		= ${SRC:.c=.o}

LIBRARY 	= ./libft.a

FLAG		= -Wall -Wextra -Werror $(INC)

INC			= -I libft -I . 

all: $(NAME)

$(NAME): $(OBJS)
	@echo "compiling $(NAME)"
	make -C libft
	gcc $(FLAG) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	@echo "compiling .o"
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean:
	rm -f $(NAME) $(LIBRARY)
	make fclean -C libft
	rm -f $(OBJS)

re: fclean all

FORCE:
