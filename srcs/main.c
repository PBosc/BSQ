/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:19:51 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 22:14:47 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "map.h"
#include "ft.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_map	*map;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map = load_map(argv[i]);
			return (0);
			if (map == NULL)
				ft_putstr("map error");
			else
				solve_map(map);
			ft_putstr("\n");
			i++;
		}
	}
	else
	{
		// Lire sur l'entree standard
	}
	return (0);
}
