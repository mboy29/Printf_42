# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboy <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 09:21:41 by mboy              #+#    #+#              #
#    Updated: 2021/03/09 08:58:41 by mboy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
		ft_parse.c\
		ft_flags.c\
		ft_add.c\
		ft_print.c\
		ft_print_char.c\
		ft_print_str.c\
		ft_print_int.c\
		ft_print_unint.c\
		ft_print_hex.c\
		ft_print_ptr.c\
		ft_print_pct.c\
		ft_base.c\
		ft_u_itoa.c

LIBFT = libft

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc 

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "\x1b[35m\nCreation of $(NAME)...\033[0m"
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rsc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[35m$(NAME) has been successfully created !\n\033[0m"
	@echo "\x1b[36m\x1b[1m__, ___      __, __, _ _, _ ___ __,\033[0m"
	@echo "\x1b[36m\x1b[1m|_   |       |_) |_) | |\ |  |  |_ \033[0m"
	@echo "\x1b[36m\x1b[1m|    | _____ |   | \ | | \|  |  |  \n\033[0m"

clean:
	@echo "\x1b[35m\nRemoval of .o files from $(NAME)...\033[0m"
	rm -f $(OBJ)
	@make clean -C $(LIBFT)
	@echo "\x1b[35m.o files from $(NAME) have been successfully removed.\n\033[0m"

fclean: clean
	@echo "\x1b[35m\nRemoval of $(NAME)...\033[0m"
	rm -f $(OBJ)
	rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\x1b[35m$(NAME) has been successfully removed.\n\033[0m"

re : fclean all

.PHONY : clean fclean all re
