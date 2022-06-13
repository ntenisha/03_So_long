# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 19:48:26 by ntenisha          #+#    #+#              #
#    Updated: 2022/06/13 21:24:57 by ntenisha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

SRCS	=	./mandatory/ft_check.c	./mandatory/ft_hook.c	./mandatory/ft_move.c\
			./mandatory/main.c	./mandatory/massiv.c	./mandatory/render.c\
			./mandatory/split.c	./mandatory/steps.c ./mandatory/ft_printf.c


SRCS_B	=	./bonus/ft_check_bonus.c	./bonus/ft_hook_bonus.c	./bonus/ft_move_bonus.c\
			./bonus/main_bonus.c	./bonus/massiv_bonus.c	./bonus/render_bonus.c\
			./bonus/split_bonus.c	./bonus/steps_bonus.c ./bonus/ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

LINKS = -lmlx -framework OpenGL -framework AppKit

HEADER	=	mandatory/solong.h

HEADER_B	=	bonus/solong.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(NAME_B):	$(OBJS_B)
			$(CC) $(SRCS_B) $(MLXFLAGS) $(CFLAGS) -o $(NAME_B)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus:		$(NAME_B)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re