/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:54:30 by exabanis          #+#    #+#             */
/*   Updated: 2018/08/11 13:24:35 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *r_str;

	if (!s1 || !s2)
		return (NULL);
	r_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!r_str)
		return (NULL);
	ft_strcpy(r_str, s1);
	return (ft_strcat(r_str, s2));
}
