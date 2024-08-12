/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_func.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 02:41:46 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/12 14:41:46 by tamatsuu         ###   ########.fr       */
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
# define PLAYER_XPM "./textures/player.xpm"
# define WALL_XPM "./textures/wall.xpm"
# define EMPTY_XPM "./textures/empty.xpm"
# define COLCTIB_XPM "./textures/collectible.xpm"
# define EXIT_XPM "./textures/exit.xpm"
# define PIX 50
# define GAME_END 2
# define NO_MOVE 0
# define MOVE 1
# define MOVE_COUNT_MSG "Move count : "

typedef struct s_char_info
{
	size_t		mov_cnt;
}	t_char_info;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map_info	*m_info;
	t_char_info	*c_info;
}	t_vars;

int		init_render(char **map, t_map_info	*m_inf);
int		key_hook(int keycode, t_vars *vars);
int		move_player(int keycode, t_vars *vars);
int		render_map(t_vars *vars);
void	render_component_img(char comp, t_vars *vars, int i, int j);

int		movable_check(t_vars *vars, int keycode);
int		check_collective(t_vars *vars, int keycode);
int		check_end(t_vars *vars, int keycode);

void	set_map_position(int keycode, t_vars *vars);
void	end_game(t_vars *vars);
void	close_window(t_vars *vars);
void	show_move_count(t_vars *vars, int mov_cnt);
int		close_btn_click(t_vars *vars);

#endif