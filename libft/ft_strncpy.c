/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 07:58:07 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/12 07:31:29 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*r_dest;
	size_t	i;

	i = -1;
	r_dest = dst;
	while (++i < len)
	{
		if (*(src))
			*(dst++) = *(src++);
		else
			*(dst++) = 0;
	}
	return (r_dest);
}
