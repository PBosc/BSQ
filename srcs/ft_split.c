/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:35:38 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:14:41 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_char_in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_strings_filling(char *str, char *charset, char **strs)
{
	int	i;
	int	k;
	int	end_last;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_char_in_string(str[i], charset) && str[i])
			i++;
		end_last = i;
		while (!(ft_char_in_string(str[i], charset)) && str[i])
		{
			strs[k][i - end_last] = str[i];
			i++;
		}
		if (i > end_last)
			k++;
	}
}

void	ft_strings_making(char *str, char *charset, char **strs)
{
	int	i;
	int	k;
	int	end_last;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_char_in_string(str[i], charset) && str[i])
			i++;
		end_last = i;
		while (!(ft_char_in_string(str[i], charset)) && str[i])
			i++;
		if (i > end_last)
		{
			strs[k] = malloc(sizeof strs[k] * (i - end_last + 1));
			strs[k][i - end_last] = '\0';
			k++;
		}
	}
}

char	**ft_strs_making(char *str, char *charset, int *len_strs)
{
	char	**strs;
	int		i;
	int		end_last;

	i = 0;
	while (str[i])
	{
		while (ft_char_in_string(str[i], charset) && str[i])
			i++;
		end_last = i;
		while (!(ft_char_in_string(str[i], charset)) && str[i])
			i++;
		if (i > end_last)
			(*len_strs)++;
	}
	strs = malloc(sizeof strs * (*len_strs + 1));
	if (strs == NULL)
		return (NULL);
	strs[*len_strs] = NULL;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		len_strs;

	len_strs = 0;
	strs = ft_strs_making(str, charset, &len_strs);
	if (len_strs == 0)
		return (strs);
	ft_strings_making(str, charset, strs);
	ft_strings_filling(str, charset, strs);
	return (strs);
}
