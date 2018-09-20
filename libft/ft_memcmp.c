/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:36:32 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/12 07:23:07 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte *x1;
	const t_byte *x2;

	x1 = s1;
	x2 = s2;
	while (n--)
		if (*x1 != *x2)
			return (*x1 - *x2);
		else
		{
			x1++;
			x2++;
		}
	return (0);
}
