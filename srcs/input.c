/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:32:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 22:13:12 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"

char	*load_file(char *path)
{
	int		fd;
	char	*buf;
	int		size;

	buf = (char *) malloc(4096 * sizeof(char));
	if (buf == NULL)
		return (NULL);
	fd = open(path, O_RDONLY, S_IROTH);
	if (fd == -1)
		return (NULL);
	size = read(fd, buf, 4095);
	buf[size] = 0;
	close(fd);
	return (buf);
}

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
{
	char	*file;
	char	*symbols;
	char	**map;
	int		lines;
	t_map	*result;

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
