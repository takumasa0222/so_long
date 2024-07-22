# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 13:13:24 by tamatsuu          #+#    #+#              #
#    Updated: 2024/07/12 16:06:01 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= test.c

OBJS		= $(SRCS:%.c=%.o)
BONUS		=
LIB			= ./libft/libft.a
BOBJS		= $(BONUS:%.c=%.o)
NAME		= so_long
AR		= ar

.PHONY: all clean fclean re norm bonus
.SILENT: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX):
	make -C mlx

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
#	make clean -C libft

fclean: clean
	rm -f $(NAME)
#	make fclean -C libft

#bonus: $(BOBJS)
#	@make -C libft
#	@cp $(LIB) $(NAME)
#	$(AR) rcs $(NAME) $(BOBJS)

#$(BOBJS): $(BONUS)
#	$(CC) $(CFLAGS) -c $(BONUS)


norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine *.h

re: fclean all
