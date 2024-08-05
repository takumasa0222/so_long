/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:43:41 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/08/06 05:12:05 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_VALIDATION_H
# define SO_LONG_VALIDATION_H

# include "../so_long.h"

# define BER_EXTENSIOIN ".ber"

int		map_validator(char **map, t_map_info *map_info);
int		check_wall_elclosure(char **bermap, t_map_info *m_info);
int		check_valid_path(char **bermap, t_map_info *m_info);
int		check_elements_integrity(char **map, t_map_info *m_info);
void	dfs_path_check(char ***tmp_map, char **map, t_map_info *tmp_m_inf);

int		arg_check(int argc, char **argv);

int		detect_invalid_char(char *str, char *valid_str, size_t col_num);
#endif