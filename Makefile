# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpotilli <tpotilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:25:01 by tpotilli@st       #+#    #+#              #
#    Updated: 2023/11/06 11:09:15 by tpotilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	srcs/main.c\
		srcs/game_manager.c\
		srcs/backtracking.c\
		srcs/game_start.c\
		srcs/hook_destroy_images.c\
		utils/gnl_utils.c\
		utils/gnl.c\
		utils/ft_putchar.c\
		utils/ft_putnbr_base.c\
		utils/ft_putnbr.c\
		utils/ft_putstr.c\
		utils/ft_printf.c\
		utils/ft_putnbr_void.c\
		utils/ft_itoa.c\
		utils/perror.c\
		utils/ft_strlen.c\
		utils/ft_split.c\
		utils/ft_memset.c\
		utils/ft_bzero.c\
		utils/ft_calloc.c\
		utils/ft_strncmp.c\
		utils/ft_strjoin.c\
		utils/ft_strlcpy.c\
		utils/ft_strdup.c\
		utils/ft_len_db_tab.c\
		parsing/verif_map.c\
		parsing/parsing.c\
		parsing/get_map.c\

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INC_PATH = ./include

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_PATH) -Imlx_linux -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re