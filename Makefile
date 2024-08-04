# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 13:13:24 by tamatsuu          #+#    #+#              #
#    Updated: 2024/08/04 23:26:48 by tamatsuu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
#CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror 
SRCS		= main.c \
so_long.c \
./utilities/map_setter.c \
./utilities/map_setter_2.c \
./utilities/map_utilities.c \
./utilities/map_utilities_2.c \
./validation/map_validater.c \
./validation/arg_validater.c \
./ft_get_next_line/get_next_line.c \
./ft_get_next_line/get_next_line_utils.c \
./render_func/render_check.c \
./render_func/render_map.c \
./render_func/render_utils.c \



OBJS		= $(SRCS:%.c=%.o)
BONUS		=
LIB			= ./libft/libft.a
BOBJS		= $(BONUS:%.c=%.o)
NAME		= so_long
AR		= ar

.PHONY: all clean fclean re norm bonus
.SILENT: all
all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(OBJS)
	@make -C mlx_linux
	@make -C libft
	$(CC) $(OBJS) -Lft -lft -L./libft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)



# $(MLX):
# 	make -C mlx

# %.o: %.c
# 	$(CC) $(CFLAGS) -Imlx -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@make clean -C mlx_linux
	@make clean -C libft
	rm -f $(OBJS) $(BOBJS)
#	make clean -C libft

fclean: clean
	@make fclean -C mlx_linux
	@make fclean -C libft
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
