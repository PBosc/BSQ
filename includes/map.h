/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:37:56 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:58:52 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	**terrain;
	int		lines;
	char	*symbols;
}	t_map;

t_map	*create_map(char **terrain, int lines, char *symbols);
int		is_valid_map(t_map *map);
void	solve_map(t_map *map);

#endif