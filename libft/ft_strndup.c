/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:24:14 by exabanis          #+#    #+#             */
/*   Updated: 2018/08/11 13:05:34 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *memdup;

	if (!(memdup = ft_strnew(n)))
		return (NULL);
	ft_strncpy(memdup, s1, n);
	return (memdup);
}
