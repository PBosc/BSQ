/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 02:16:22 by pbosc             #+#    #+#             */
/*   Updated: 2022/07/26 02:37:36 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
=======
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:35:38 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:14:41 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_char_in_string(char c, char *str)
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
{
	int	i;

	i = 0;
	while (str[i])
<<<<<<< HEAD
		i++;
	return (i);
}

int	is_in_arr(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_in_arr(str[i], charset))
			i++;
		if (!is_in_arr(str[i], charset) && str[i])
		{
			count++;
			while (!is_in_arr(str[i], charset) && str[i])
				i++;
		}
	}
	return (count + 1);
}

char	*next_word(int *i, char *str, char *charset)
{
	int		size;
	int		j;
	char	*next_word;

	j = 0;
	size = 0;
	while (is_in_arr(str[*i], charset))
		(*i)++;
	while (!is_in_arr(str[*i + size], charset) && str[*i + size])
		size++;
	next_word = (char *) malloc((size + 1) * sizeof(char));
	if (next_word == NULL)
		return (NULL);
	while (j < size)
	{
		next_word[j] = str[*i];
		(*i)++;
		j++;
	}
	next_word[j] = 0;
	return (next_word);
=======
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
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
}

char	**ft_split(char *str, char *charset)
{
<<<<<<< HEAD
	int		i;
	int		nb_words;
	char	**output;
	int		word;

	i = 0;
	word = 0;
	nb_words = count_words(str, charset);
	output = malloc(nb_words * sizeof(char *));
	if (output == NULL)
		return (NULL);
	while (word < nb_words - 1)
		output[word++] = next_word(&i, str, charset);
	output[word] = 0;
	return (output);
=======
	char	**strs;
	int		len_strs;

	len_strs = 0;
	strs = ft_strs_making(str, charset, &len_strs);
	if (len_strs == 0)
		return (strs);
	ft_strings_making(str, charset, strs);
	ft_strings_filling(str, charset, strs);
	return (strs);
>>>>>>> 0e3b78cc27457c83d8c4763007f3f18c05558b76
}
