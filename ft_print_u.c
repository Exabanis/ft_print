/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 07:18:14 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:21:14 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_put_space(t_pist *jar, char *str)
{
	int		s_len;

	s_len = ft_strlen(str) + (jar->oh_prex ? ft_strlen(jar->oh_prex) : 0) +
		(jar->zeros ? ft_strlen(jar->zeros) : 0);
	if (jar->min_w && (!(jar->flag3) || jar->flag4 || jar->h) &&
			jar->min_w > s_len)
	{
		jar->spaces = ft_strnew(jar->min_w - s_len);
		while ((jar->min_w - s_len) > 0)
		{
			jar->spaces = ft_strcat(jar->spaces, " ");
			jar->min_w--;
		}
	}
	return (jar->spaces);
}

char	*ft_put_zero(t_pist *jar, char *str)
{
	int		s_len;
	int		prex;

	s_len = ft_strlen(str) + (jar->oh_prex ? ft_strlen(jar->oh_prex) : 0);
	prex = jar->oh_prex == 0 ? 0 : ft_strlen(jar->oh_prex);
	if (jar->h && jar->max_w > s_len - prex)
	{
		jar->zeros = ft_strnew(jar->max_w - s_len);
		while ((jar->max_w - s_len + prex) > 0)
		{
			jar->zeros = ft_strjoin(jar->zeros, "0");
			jar->max_w--;
		}
	}
	if (jar->min_w && jar->flag3 && !(jar->flag4) && !(jar->h) &&
			jar->min_w > s_len)
	{
		jar->zeros = ft_strnew(jar->min_w - s_len);
		while ((jar->min_w - s_len) > 0)
		{
			jar->zeros = ft_strcat(jar->zeros, "0");
			jar->min_w--;
		}
	}
	return (jar->zeros);
}

char	*ft_utoa_base(uintmax_t n, int base)
{
	char			*s;
	size_t			nlen;
	uintmax_t		num;

	nlen = 1;
	num = n;
	while (num /= base)
		nlen++;
	if (!(s = ft_strnew(nlen)))
		return (NULL);
	while (nlen > 0)
	{
		s[--nlen] = (n % base) + ((n % base > 9) ? 'a' - 10 : '0');
		n /= base;
	}
	s[--nlen] = '\0';
	return (s);
}

void	ft_print_u(uintmax_t n, t_pist *jar, int base)
{
	char	*str;
	int		i;
	size_t	s_len;

	i = -1;
	str = ft_utoa_base(n, base);
	(jar->h && !(jar->max_w) && !n) ? 0 : ft_prefix(jar, n);
	if (jar->con_c == 'X')
		while (str[++i] != '\0')
			str[i] = ft_toupper(str[i]);
	jar->zeros = ft_put_zero(jar, str);
	jar->spaces = ft_put_space(jar, str);
	s_len = (!(jar->oh_prex) ? 0 : ft_strlen(jar->oh_prex)) + (!(jar->zeros) ?
			0 : ft_strlen(jar->zeros)) + (!(jar->spaces) ? 0 :
			ft_strlen(jar->spaces));
	!(jar->flag4) ? ft_putstr(jar->spaces) : 0;
	!(jar->oh_prex) ? 0 : ft_putstr(jar->oh_prex);
	!(jar->zeros) ? 0 : ft_putstr(jar->zeros);
	if (!(jar->h && !(jar->max_w) && !n))
		ft_putstr(str);
	!(jar->flag4) ? 0 : ft_putstr(jar->spaces);
	jar->count += s_len + (!(jar->h && !jar->max_w && !n) ? ft_strlen(str) : 0);
	free(str);
	return ;
}
