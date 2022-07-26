/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:05:25 by pbosc             #+#    #+#             */
/*   Updated: 2022/07/26 04:26:44 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/ft.h"
#include "../includes/input.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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
	int fd;
	char buffer[5000000];
	if (argc < 2)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	int ret = read(fd, buffer, 5000000);
	printf("%d", ret);
	map = parse_stdin(buffer);
	char **map_finished = change_square(map, squarify(mathify(map), map->lines));
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
	i = 0;
	while (i < map->lines)
		free(map_finished[i++]);
	free(map_finished);
	i = 0;
	while (i < map->lines)
		free(map->terrain[i++]);
	free(map->terrain);
	free(map);
	return 0;
}
