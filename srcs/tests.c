/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:05:25 by pbosc             #+#    #+#             */
/*   Updated: 2022/07/26 02:38:28 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/ft.h"
#include "../includes/input.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **change_square(t_map *map, int **mathmap);
int		**mathify(t_map *map);
int **squarify(int **mathmap, int size);
t_map	*parse_stdin(char *map);

int main(int argc, char *argv[])
{
	t_map *map;
	int i = 0;
	int j = 0;
	char c;
	// map = malloc(sizeof(t_map));
	// map->terrain = malloc(9 * sizeof(char *));
	// while (i < 9)
	// 	map->terrain[i++] = malloc(9);
	// map->lines = 9;
	// map->symbols = "9.ox";
	// map->terrain[0] = "o.....o..";
	// map->terrain[1] = ".......oo";
	// map->terrain[2] = ".......o.";
	// map->terrain[3] = ".....o...";
	// map->terrain[4] = ".........";
	// map->terrain[5] = "......o..";
	// map->terrain[6] = "...o.....";
	// map->terrain[7] = "o..o....o";
	// map->terrain[8] = "o.....o..";
	char buffer[4096];
	read(0, buffer, 4096);
	map = parse_stdin(buffer);
	char **map_finished = change_square(map, squarify(mathify(map), map->lines));
	int **mathmap = squarify(mathify(map), 9);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while(j < map->lines)
		{
			write(1, &map_finished[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return 0;
}
