/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:37:56 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 00:36:50 by pbosc            ###   ########.fr       */
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

typedef struct s_point
{
	int value;
	int x;
	int y;
}	t_point;

t_map	*create_map(char **terrain, int lines, char *symbols);
int		is_valid_map(t_map *map);
void	solve_map(t_map *map);

#endif