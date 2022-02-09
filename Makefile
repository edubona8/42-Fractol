# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebonamic <ebonamic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 01:30:20 by ebonamic          #+#    #+#              #
#    Updated: 2022/02/02 01:30:21 by ebonamic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.DEFAULT_GOAL    :=    all

NAME = fractol

SRC = fractol.c draw.c init.c color.c zoom.c key.c fractol_algs.c utils.c \
utils_2.c

OBJS = $(SRC:.c=.o)

FLAG = -lbsd -lmlx -lXext -lX11 -lm -lz

CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAG) $(FLAG)
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c
	gcc $(CFLAG) -c $< -o $@
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"

clean:
	rm -f $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: clean fclean re all