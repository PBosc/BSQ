/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:19:51 by vegret            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/26 02:35:45 by pbosc            ###   ########.fr       */
=======
/*   Updated: 2022/07/25 22:14:47 by vegret           ###   ########.fr       */
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"
#include "map.h"
#include "ft.h"

<<<<<<< HEAD
// int	main(int argc, char *argv[])
// {
// 	int		i;
// 	t_map	*tmp;

// 	if (argc > 1)
// 	{
// 		i = 1;
// 		while (i < argc)
// 		{
// 			tmp = load_map(argv[i]);
// 			if (tmp == NULL)
// 				ft_putstr("map error");
// 			else
// 				solve_map(tmp);
// 			ft_putstr("\n");
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		// Lire sur l'entree standard
// 	}
// 	return (0);
// }
=======
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
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
