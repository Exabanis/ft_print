/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 07:16:01 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:21:56 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_b(uintmax_t n)
{
	char		*s;
	size_t		nlen;
	intmax_t	number;

	nlen = 1;
	number = n;
	while (n /= 10)
		nlen++;
	if (!(s = ft_strnew(nlen)))
		return (NULL);
	s[--nlen] = number % 10 + '0';
	while (number /= 10)
		s[--nlen] = number % 10 + '0';
	if (s[0] == '\'')
		return ("9223372036854775808");
	return (s);
}

void	ft_put_sign(t_pist *jar, intmax_t n)
{
	if (n >= 0)
	{
		if (jar->flag1)
			jar->oh_prex = "+";
		else if (jar->flag2)
			jar->oh_prex = " ";
	}
	else if (n < 0)
		jar->oh_prex = "-";
	return ;
}

void	ft_print_s(intmax_t n, t_pist *jar)
{
	char	*str;
	int		i;
	size_t	s_len;

	i = 0;
	str = n < 0 ? ft_itoa_b(-n) : ft_itoa_b(n);
	ft_put_sign(jar, n);
	jar->zeros = ft_put_zero(jar, str);
	jar->spaces = ft_put_space(jar, str);
	s_len = ft_strlen(str) + (!(jar->oh_prex) ? 0 : ft_strlen(jar->oh_prex)) +
		(!(jar->zeros) ? 0 : ft_strlen(jar->zeros)) + (!(jar->spaces) ? 0 :
				ft_strlen(jar->spaces));
	!(jar->flag4) ? ft_putstr(jar->spaces) : 0;
	(!(jar->oh_prex) && (jar->flag3 || jar->flag2)) ? 0 :
		ft_putstr(jar->oh_prex);
	!(jar->zeros) ? 0 : ft_putstr(jar->zeros);
	if (!(jar->h && !jar->max_w && !n))
		ft_putstr(str);
	!(jar->flag4) ? 0 : ft_putstr(jar->spaces);
	jar->count += s_len;
	if (ft_strcmp(str, "9223372036854775808") != 0)
		free(str);
	return ;
}
