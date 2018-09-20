/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 07:03:46 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:24:06 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_space(t_pist *jar)
{
	while (jar->min_w > 0)
	{
		ft_putchar((jar->flag3 == '0' && jar->flag4 == 0) ? '0' : ' ');
		jar->count++;
		jar->min_w--;
	}
	return ;
}

void	ft_print_str(t_pist *jar, char *str)
{
	str = !str ? "(null)" : str;
	str = jar->h == 0 ? str : ft_strndup(str, jar->max_w);
	jar->min_w -= ft_strlen(str);
	if (jar->flag4 == 0)
		ft_space(jar);
	ft_putstr(str);
	jar->count += ft_strlen(str);
	if (jar->flag4 == '-')
		ft_space(jar);
	return ;
}

void	ft_print_char(t_pist *jar, char c)
{
	jar->min_w--;
	if (jar->flag4 == 0)
		ft_space(jar);
	ft_putchar(c);
	jar->count++;
	if (jar->flag4 == '-')
		ft_space(jar);
	return ;
}

void	ft_prefix(t_pist *jar, uintmax_t n)
{
	if ((jar->con_c == 'o' || jar->con_c == 'O') && jar->flag0 == '#' &&
			(n || (!n && jar->h && !(jar->max_w))))
	{
		jar->oh_prex = "0";
	}
	else if ((((jar->con_c == 'x' || jar->con_c == 'X') && jar->flag0 == '#'
					&& n)) || jar->con_c == 'p')
	{
		if (jar->con_c == 'X')
			jar->oh_prex = "0X";
		else
			jar->oh_prex = "0x";
	}
	return ;
}

void	ft_convert(t_pist *jar, va_list argue, char c)
{
	if (jar->con_c == 'c')
		ft_print_char(jar, va_arg(argue, int));
	else if (jar->con_c == 'C')
		ft_print_wchar(jar, va_arg(argue, wint_t));
	else if (jar->con_c == 's')
		ft_print_str(jar, va_arg(argue, char *));
	else if (jar->con_c == 'S')
		ft_print_wstr(jar, va_arg(argue, wchar_t *));
	else if (jar->con_c == 'u' || jar->con_c == 'U')
		ft_uint_dir(jar, argue);
	else if (jar->con_c == 'i' || jar->con_c == 'd' || jar->con_c == 'D')
		ft_int_dir(jar, argue);
	else if (jar->con_c == 'o' || jar->con_c == 'O')
		ft_oct_dir(jar, argue);
	else if (jar->con_c == 'x' || jar->con_c == 'X' || jar->con_c == 'p')
		ft_hex_dir(jar, argue);
	else
		ft_print_char(jar, c);
	return ;
}
