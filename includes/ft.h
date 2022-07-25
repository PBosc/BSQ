/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:12:32 by vegret            #+#    #+#             */
/*   Updated: 2022/07/25 18:54:36 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_atoi(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_skipnumbers(char *str);
char	**ft_remove_first_element(char **str);
void	ft_putstr(char *str);

#endif