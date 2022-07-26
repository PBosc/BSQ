/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
{
	int	i;

	i = 0;
	while (str[i])
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
}

char	**ft_split(char *str, char *charset)
{
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
}
