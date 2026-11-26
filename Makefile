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
LIB		:=  -L. -lfdf -Lprintf -lftprintf -lm  \
			-Lminilibx-linux -lmlx				\
			-lXext -lX11 -lz
# mlx + dep(xorg + x11 + zlib) + fdf + math + ft_printf
# mlx lib in last otherwise it's discarded before lfdf use them

#C_FILES	:= $(wildcard *.c)
C_FILES	:= 	fdf.c fdf_init.c fdf_parsing.c fdf_hook.c fdf_redraw.c \
			fdf_draw_line.c fdf_draw_iso.c fdf_cleanup.c \
			fdf_util.c fdf_util2.c \
			get_next_line.c get_next_line_utils.c \
			parrot.c parrot2.c parrot3.c
			
C_BONUS := 
OBJ		:= $(C_FILES:.c=.o)
OBJ_B	:= $(C_BONUS:.c=.o)
NAME	:= libfdf.a

MLX_PATH:= ./minilibx-linux/
MLX_NAME:= libmlx.a

PRINT_PATH:= ./printf/
PRINT_NAME:= libftprintf.a

all: $(NAME) fdf

$(NAME): $(OBJ)
	$(MAKE) -sC $(PRINT_PATH)
	$(MAKE) -sC $(MLX_PATH)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS)
	
bonus: $(OBJ) $(OBJ_B)
	ar -rcs $(NAME) $(OBJ) $(OBJ_B)
	
clean:
	@rm -f $(OBJ) $(OBJ_B)
	$(MAKE) -sC $(PRINT_PATH) clean
	$(MAKE) -sC $(MLX_PATH) clean
	
fclean:	clean
	@rm -f $(NAME)
	@rm -f fdf
	$(MAKE) -sC $(PRINT_PATH) fclean

re:	fclean all

fdf: $(NAME)
	$(CC) fdf.c -o fdf $(CFLAGS) $(LIB)
	
.PHONY:	all bonus clean fclean re
