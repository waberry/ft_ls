# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berry <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/27 18:40:51 by berry             #+#    #+#              #
#    Updated: 2019/05/30 16:07:30 by berry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

CC=gcc

CFLAGS=-Wall -Wextra -Werror
SRC=./main.c\
	./error.c ./utils1.c ./utils2.c ./utils3.c ./displays.c\
    ./sorts.c ./parsing.c ./colors.c\
    ./mylist_methods1.c\
    ./mylist_methods2.c ./getters1.c ./getters2.c\
    ./getters3.c

OBJ=$(SRC:.c=.o)

RM=rm -f

LIBFT= ./libft/libft.a

$(NAME):$(OBJ)
		@make -C ./libft/
		@$(CC) $(CFLAGS) -c $(SRC)
		@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
		@echo "ft_ls build successful"

all:$(NAME)

clean:
	@$(RM) $(OBJ)
	@make clean -C ./libft/
	@echo "ft_ls clean successful"

fclean: clean
		@rm -f $(NAME)
		@make fclean -C ./libft/
		@echo "ft_ls fclean successful"

re: fclean all

.PHONY: all clean fclean re
