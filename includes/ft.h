/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbosc <pbosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:12:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/26 04:20:14 by pbosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_antoi(char *str, int n);
char	**ft_split(char *str, char *charset);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);

#endif