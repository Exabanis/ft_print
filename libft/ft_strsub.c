/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:58:20 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/13 12:37:43 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new_s;

	if (!s || start + len > ft_strlen(s))
		return (NULL);
	new_s = ft_strnew(len);
	if (!new_s)
		return (NULL);
	return (ft_strncpy(new_s, s + start, len));
}
