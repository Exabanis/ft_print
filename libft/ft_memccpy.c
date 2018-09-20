/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:18:18 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/12 07:22:40 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		if (*s == (char)c)
			return ((void *)d);
		s++;
	}
	return (NULL);
}
