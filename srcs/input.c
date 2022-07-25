/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:32:45 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:41:39 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	lines = ft_atoi(map[0]);
	symbols = ft_skipnumbers(map[0]);
	map = ft_remove_first_element(map);
	result = create_map(map, lines, symbols);
	if (!is_valid_map(result))
		return (NULL);
	return (result);
}
