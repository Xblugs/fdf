# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cczerwin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 15:48:21 by cczerwin          #+#    #+#              #
#    Updated: 2024/10/30 15:48:24 by cczerwin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
#C_FILES	:= $(wildcard *.c)
C_FILES	:= 	ft_printf.c ft_parsing.c ft_padding.c \
			ft_printcs.c ft_printdi.c ft_printu.c ft_printx.c ft_printp.c\
			ft_util.c ft_util_pow.c \
			ft_atoi.c
			
C_BONUS := 
OBJ		:= $(C_FILES:.c=.o)
OBJ_B	:= $(C_BONUS:.c=.o)
NAME	:= libftprintf.a


all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
	
bonus: $(OBJ) $(OBJ_B)
	ar -rcs $(NAME) $(OBJ) $(OBJ_B)
	
clean:
	rm -f $(OBJ) $(OBJ_B)
	
fclean:	clean
	rm -f $(NAME)

re:	fclean all

exec: all clean
	rm -f ft_printf
	$(CC) ft_printf.c -o ft_printf $(CFLAGS) -L. -lftprintf
	
.PHONY:	all bonus clean fclean re
