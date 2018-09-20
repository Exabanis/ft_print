/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:59:11 by exabanis          #+#    #+#             */
/*   Updated: 2018/06/13 12:38:46 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_s;
	int		before_s;
	int		after_s;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	before_s = 0;
	after_s = 0;
	while (ft_isspace(*(s + ++i)))
		before_s++;
	while (*(s + i++))
		after_s = ft_isspace(*(s + i - 1)) ? after_s + 1 : 0;
	new_s = ft_strnew(ft_strlen(s) - after_s - before_s);
	if (!new_s)
		return (NULL);
	return (ft_strncpy(new_s, s + before_s, ft_strlen(s) - after_s - before_s));
}
