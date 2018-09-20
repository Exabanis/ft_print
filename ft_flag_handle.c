/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 08:56:29 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:30:01 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		ft_pre_print(t_pist *jar, t_bist *cup)
{
	if (ft_strchr(MOD, *(cup->f_str)))
	{
		if (*(cup->f_str) == 'h' && *(cup->f_str + 1) == 'h')
		{
			jar->len_m = 6;
			cup->f_str++;
		}
		else if (*(cup->f_str) == 'l' && *(cup->f_str + 1) == 'l')
		{
			jar->len_m = 1;
			cup->f_str++;
		}
		else if (*(cup->f_str) == 'h')
			jar->len_m = 2;
		else if (*(cup->f_str) == 'l')
			jar->len_m = 3;
		else if (*(cup->f_str) == 'j')
			jar->len_m = 4;
		else if (*(cup->f_str) == 'z')
			jar->len_m = 5;
		cup->f_str++;
	}
	return ;
}

void		ft_get_max(t_pist *jar, va_list argue, t_bist *cup)
{
	cup->f_str++;
	if (*(cup->f_str) == '*')
	{
		jar->max_w = va_arg(argue, int);
		cup->f_str++;
	}
	else
	{
		cup->l_str = (char *)malloc(sizeof(char *));
		while (ft_isdigit(*(cup->f_str)))
		{
			cup->l_str[cup->indx] = *(cup->f_str);
			cup->f_str++;
			cup->indx++;
		}
		cup->l_str[cup->indx] = 0;
		jar->max_w = cup->l_str ? ft_atoi(cup->l_str) : 0;
		free(cup->l_str);
		cup->indx = 0;
	}
	jar->h = 1;
	return ;
}

void		ft_get_min(t_pist *jar, va_list argue, t_bist *cup)
{
	if (*(cup->f_str) == '*')
	{
		jar->min_w = va_arg(argue, int);
		cup->f_str++;
		if (jar->min_w < 0)
		{
			jar->flag4 = '-';
			jar->min_w *= -1;
		}
	}
	else
	{
		cup->l_str = (char *)malloc(sizeof(char *));
		while (ft_isdigit(*(cup->f_str)))
		{
			cup->l_str[cup->indx++] = *(cup->f_str);
			cup->f_str++;
		}
		cup->l_str[cup->indx] = 0;
		jar->min_w = cup->l_str ? ft_atoi(cup->l_str) : 0;
		free(cup->l_str);
		cup->l_str = 0;
		cup->indx = 0;
	}
	return ;
}

int			ft_get_flag(t_pist *jar, char c)
{
	if (ft_strchr(FLAGS, c))
	{
		if (c == '#')
			jar->flag0 = c;
		else if (c == '+')
			jar->flag1 = c;
		else if (c == ' ')
			jar->flag2 = c;
		else if (c == '0')
			jar->flag3 = c;
		else if (c == '-')
			jar->flag4 = c;
		return (1);
	}
	return (0);
}

void		ft_flag_handle(t_pist *jar, va_list argue, t_bist *cup)
{
	if (*(cup->f_str) == '%')
	{
		ft_putchar('%');
		jar->count++;
	}
	else
	{
		while (ft_get_flag(jar, *(cup->f_str)))
			cup->f_str++;
		ft_get_min(jar, argue, cup);
		if (*(cup->f_str) == '.')
			ft_get_max(jar, argue, cup);
		ft_pre_print(jar, cup);
		if (ft_strchr(CONV_C, *(cup->f_str)))
			jar->con_c = *(cup->f_str);
		ft_convert(jar, argue, *(cup->f_str));
	}
	cup->f_str++;
	return ;
}
