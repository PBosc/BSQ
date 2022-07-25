/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:13:18 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:55:09 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, (str + i), 1);
		i++;
	}
}

char	**ft_remove_first_element(char **str, int size)
{
	char	**result;
	int		i;

	result = malloc((size - 1) * sizeof(char *));
	i = 1;
	while (i < size)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
