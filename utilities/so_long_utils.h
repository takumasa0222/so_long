/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:03:07 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/12 14:59:51 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H
# include "../so_long.h"

//map_setter
void	set_map_info_col(t_map_info *map_info, unsigned int col);
void	set_map_info_row(t_map_info *map_info, unsigned int row);
void	set_map_info_c_cnt(t_map_info *map_info, unsigned int c_cnt);
void	set_map_info_p_cnt(t_map_info *map_info, unsigned int p_cnt);
void	set_map_info_e_cnt(t_map_info *map_info, unsigned int e_cnt);

//map_setter_2
void	set_map_info_x(t_map_info *map_info, ssize_t x);
void	set_map_info_y(t_map_info *map_info, ssize_t y);

//map_utilities
int		init_map(char *map_file_path, char ***bermap, t_map_info *map_i);
int		init_tmp_map(char ***tmp_m, t_map_info **tmp_m_inf, t_map_info *m_inf);
int		get_map(int fd, char ***bermap, t_map_info *map_i);
int		free_map(char ***bermap, unsigned int l);

//map_utilities_2
int		ft_char_find_place(char *set, int s);
int		cnt_word(char *str, int c);

void	show_error_msg(int err_no);
#endif