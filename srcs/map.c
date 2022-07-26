/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:48:06 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 22:14:31 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"

t_map	*create_map(char **terrain, int lines, char *symbols)
{
	t_map	*result;

	result = malloc(sizeof(t_map));
	result->terrain = terrain;
	result->lines = lines;
	result->symbols = symbols;
	return (result);
}

int	str_only_contains(char *str, char *constructors)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (str[i])
	{
		j = 0;
		found = 0;
		while (constructors[j])
		{
			if (constructors[j] == str[i])
				found = 1;
			j++;
		}
		if (!found)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_terrain(t_map *map)
{
	int	i;
	int	first_len;

	i = 0;
	first_len = ft_strlen(map->terrain[0]);
	if (map->lines < 1 || first_len < 1)
		return (0);
	// FIXME Segfault
	while (i < map->lines)
	{
		if (ft_strlen(map->terrain[i]) != first_len
			|| str_only_contains(map->terrain[i], map->symbols))
			// Chaque ligne finit bien par un \n?
			return (0);
		i++;
	}
	return (1);
}

int	str_char_count(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

int	is_valid_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->symbols == NULL)
		return (0);
	while (map->symbols[i])
	{
		if (i > 2 || map->symbols[i] < 31 || map->symbols[i] > 126
			|| str_char_count(map->symbols, map->symbols[i]) > 1)
			return (0);
		i++;
	}
	return (is_valid_terrain(map));
}
