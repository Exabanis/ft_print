/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:22:29 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/12 07:31:22 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < (int)n - 1)
		i++;
	if (n)
		return ((t_byte)s1[i] - (t_byte)s2[i]);
	return (0);
}
