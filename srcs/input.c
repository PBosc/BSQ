/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:32:45 by vegret            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/26 02:37:07 by pbosc            ###   ########.fr       */
=======
/*   Updated: 2022/07/25 22:13:12 by vegret           ###   ########.fr       */
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
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

<<<<<<< HEAD
t_map	*parse_stdin(char *map)
=======
char	*parse_symbols(char *str)
{
	char	*symbols;
	int		strlen;

	strlen = ft_strlen(str);
	if (strlen < 4)
		return (NULL);
	symbols = malloc(sizeof(char) * 3);
	symbols[0] = str[strlen - 3];
	symbols[1] = str[strlen - 2];
	symbols[2] = str[strlen - 1];
	return (symbols);
}

t_map	*load_map(char *path)
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
{
	t_map *map_parsed;
	char *symb;
	int size;
	int i;
	char **split_map;

<<<<<<< HEAD
	size = 9; //todo : changer ca
	i = 0;
	split_map = ft_split(map, "\n");
	map_parsed = malloc(sizeof(t_map));
	map_parsed->terrain = malloc(9 * sizeof(char *));
	while (i < size)
		map_parsed->terrain[i++] = malloc(9);
	map_parsed->lines = size;
	map_parsed->symbols = split_map[0];
	i = 1;
	while(i < size + 1)
	{
		map_parsed->terrain[i - 1] = split_map[i];
		i++;
	}
	return (map_parsed);
}
=======
	file = load_file(path);
	if (file == NULL)
		return (NULL);
	map = ft_split(file, "\n");
	lines = ft_antoi(map[0], ft_strlen(map[0]) - 3);
	symbols = parse_symbols(map[0]);
	map += 1;
	result = create_map(map, lines, symbols);
	if (!is_valid_map(result))
		return (NULL);
	return (result);
}
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
