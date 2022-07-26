/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:32:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 04:27:30 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"

// char	*load_file(char *path)
// {
// 	int		fd;
// 	char	*buf;
// 	int		size;

// 	buf = (char *) malloc(4096 * sizeof(char));
// 	if (buf == NULL)
// 		return (NULL);
// 	fd = open(path, O_RDONLY, S_IROTH);
// 	if (fd == -1)
// 		return (NULL);
// 	size = read(fd, buf, 4095);
// 	buf[size] = 0;
// 	close(fd);
// 	return (buf);
// }

// t_map	*load_map(char *path)
// {
// 	char	*file;
// 	char	*symbols;
// 	char	**map;
// 	int		lines;
// 	t_map	*result;

// 	file = load_file(path);
// 	if (file == NULL)
// 		return (NULL);
// 	map = ft_split(file, "\n");
// 	lines = ft_atoi(map[0]);
// 	symbols = ft_skipnumbers(map[0]);
// 	map = ft_remove_first_element(map);
// 	result = create_map(map, lines, symbols);
// 	if (!is_valid_map(result))
// 		return (NULL);
// 	return (result);
// }

t_map	*parse_stdin(char *map)
{
	t_map *map_parsed;
	char *symb;
	int size;
	int i;
	char **split_map;

	size = 1000; //todo : changer ca
	i = 0;
	split_map = malloc(size * sizeof(char *));
	while (i < size)
		split_map[i++] = malloc(size * sizeof(char));
	split_map = ft_split(map, "\n");
	map_parsed = malloc(sizeof(t_map));
	map_parsed->terrain = malloc(size * sizeof(char *));
	while (i < size)
		map_parsed->terrain[i++] = malloc(size * sizeof(char));
	map_parsed->lines = size;
	map_parsed->symbols = split_map[0];
	i = 1;
	while(i < size + 1)
	{
		map_parsed->terrain[i - 1] = split_map[i];
		i++;
	}
	i = 0;
	return (map_parsed);
}
