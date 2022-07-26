/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_BSQ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:40:09 by pbosc             #+#    #+#             */
/*   Updated: 2022/07/26 04:06:25 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/ft.h"
#include "../includes/input.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		**mathify(t_map *map)
{
	int	**math_map;
	int size;
	int	i;
	int	j;

	size = map->lines;
	math_map = malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
		math_map[i++] = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map->terrain[i][j] == '.')
				math_map[i][j] = 1;
			else
				math_map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (math_map);
}

int	find_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return(a);
	if (b <= a && b <= c)
		return(b);
	if (c <= b && c <= a)
		return(c);
}

int **squarify(int **mathmap, int size)
{
	int		i;
	int		j;
	int		k;
	int		**new_map;
	char c;

	new_map = malloc(size * sizeof(int *));
	i = 0;
	j = 0;
	while (i < size)
		new_map[i++] = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		new_map[i][j] = mathmap[i][j];
		i++;
	}
	i = 0;
	while (j < size)
	{
		new_map[i][j] = mathmap[i][j];
		j++;
	}
	i = 1;
	while(i < size)
	{
		j = 1;
		while (j < size)
		{
			if (mathmap[i][j] != 0)
				new_map[i][j] = find_min(new_map[i - 1][j], new_map[i][j - 1], new_map[i - 1][j - 1]) + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
		free(mathmap[i++]);
	free(mathmap);
	return (new_map);
}

t_point find_matrix_max(int **matrix, int size)
{
	t_point result;
	int max;
	int i;
	int j;
	int coord[2];

	max = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (matrix[i][j] > max)
			{
				max = matrix[i][j];
				coord[0] = i;
				coord[1] = j;
			}
			j++;
		}
		i++;
	}
	result.value = max;
	result.x = coord[0];
	result.y = coord[1];
	return (result);
}

char **change_square(t_map *map, int **mathmap)
{
	t_point max;
	int i;
	int j;
	char c;
	char **map_terrain;

	i = 0;
	j = 0;
	max = find_matrix_max(mathmap, map->lines);
	map_terrain = malloc(map->lines * sizeof(char *));
	while (i < map->lines)
		map_terrain[i++] = malloc(map->lines * sizeof(char));
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->lines)
		{
			map_terrain[i][j] = map->terrain[i][j];
			j++;
		}
		i++;
	}
	i = max.x;
	while (i > max.x - max.value)
	{
		j = max.y;
		while (j > max.y - max.value)
		{
			map_terrain[i][j] = 'x';
			j--;
		}
		i--;
	}
	i = 0;
	while (i < map->lines)
		free(mathmap[i++]);
	free(mathmap);
	return (map_terrain);
}