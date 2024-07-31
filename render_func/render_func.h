/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:41:46 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/01 03:41:09 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FUNC_H
# define RENDER_FUNC_H
# include "../so_long.h"

# define WIN_TITLE "so_long"
# define UP_KEY 105
# define DOWN_KEY 107
# define RIGHT_KEY 108
# define LEFT_KEY 106
# define ESC 65307
# define PLAYER 'P'
# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER_XPM "../textures/player.xpm"
# define WALL_XPM "../textures/wall.xpm"
# define EMPTY_XPM "../textures/empty.xpm"
# define COLCTIB_XPM "../textures/collectible.xpm"
# define EXIT_XPM "../textures/exit.xpm"
# define PIX 64
# define GAME_END 1
# define NO_MOVE 0
# define MOVE 1

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_info	*m_info;
}	t_vars;

#endif