# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klenesle <klenesle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/13 00:41:09 by klenesle          #+#    #+#              #
#    Updated: 2026/11/23 08:17:32 by klenesle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SOURCES =	ft_printf.c ft_print_percent.c ft_print_c.c \
			ft_print_s.c ft_print_p.c ft_print_d_i.c \
			ft_print_u.c ft_print_x.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(AR) $(NAME) $(OBJECTS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJECTS)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJECTS)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re