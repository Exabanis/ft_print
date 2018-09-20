/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 06:44:25 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:17:56 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	p_w_char(wchar_t w_char, char *tab)
{
	int		len;

	len = 0;
	if (w_char <= 0xFF)
		tab[len++] = w_char;
	else if (w_char < 0x0800)
	{
		tab[len++] = ((w_char >> 6) & 0x1F) | 0xC0;
		tab[len++] = ((w_char >> 0) & 0x3F) | 0x80;
	}
	else if (w_char < 0x010000)
	{
		tab[len++] = ((w_char >> 12) & 0x0F) | 0xE0;
		tab[len++] = ((w_char >> 6) & 0x3F) | 0x80;
		tab[len++] = ((w_char >> 0) & 0x3F) | 0x80;
	}
	else if (w_char < 0x110000)
	{
		tab[len++] = ((w_char >> 18) & 0x07) | 0xF0;
		tab[len++] = ((w_char >> 12) & 0x3F) | 0x80;
		tab[len++] = ((w_char >> 6) & 0x3F) | 0x80;
		tab[len++] = ((w_char >> 0) & 0x3F) | 0x80;
	}
	return (len);
}

int			ft_wclen(wchar_t w_char)
{
	int		len;

	len = 0;
	if (w_char <= 0xFF)
		len = 1;
	else if (w_char < 0x0800)
		len = 2;
	else if (w_char < 0x010000)
		len = 3;
	else if (w_char < 0x110000)
		len = 4;
	return (len);
}

size_t		ft_wstrlen(wchar_t *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len += ft_wclen(*str);
		str++;
	}
	return (len);
}

void		ft_wchar(t_pist *jar, wchar_t c)
{
	int		len;
	char	tab[4];

	len = p_w_char(c, tab);
	write(1, tab, len);
	jar->count += len;
	return ;
}

void		ft_wstr(t_pist *jar, wchar_t *str)
{
	while (*str)
	{
		ft_wchar(jar, *str);
		str += 1;
	}
	return ;
}
