/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:19:51 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:57:43 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "map.h"
#include "ft.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_map	*tmp;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			tmp = load_map(argv[i]);
			if (tmp == NULL)
				ft_putstr("map error");
			else
				solve_map(tmp);
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
