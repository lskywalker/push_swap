# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsmit <lsmit@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/30 16:18:16 by lsmit         #+#    #+#                  #
#    Updated: 2021/07/26 20:33:59 by lsmit         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = main.c

SRC = $(addprefix src/, $(SRC_FILES))

OBJS := ${SRC:.c=.o}

LIBRARY = ./libft.a

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	gcc $(FLAG) -I libft/libft.h -I pushswap.h $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean:
	rm -f $(NAME) $(LIBRARY)
	make fclean -C libft
	rm -f $(OBJS)

re: fclean all

LIBFT: FORCE
	@echo "Compiling libft"
	make -C libft
	mv libft/$(LIBRARY) .

FORCE:
