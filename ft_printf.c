/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 06:45:19 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:28:19 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_pist	*ft_initial_h(t_pist *jar)
{
	if (!(jar = (t_pist *)malloc(sizeof(t_pist))))
	{
		ft_putstr("FAILED");
		return (0);
	}
	jar->oh_prex = 0;
	jar->con_c = 0;
	jar->zeros = 0;
	jar->spaces = 0;
	jar->flag0 = 0;
	jar->flag1 = 0;
	jar->flag2 = 0;
	jar->flag3 = 0;
	jar->flag4 = 0;
	jar->len_m = 0;
	jar->max_w = 0;
	jar->min_w = 0;
	jar->h = 0;
	jar->p = 0;
	jar->count = 0;
	return (jar);
}

t_bist	*ft_initial_f(t_bist *cup)
{
	if (!(cup = (t_bist *)malloc(sizeof(t_bist))))
	{
		ft_putstr("FAILED TO INITIALIZE");
		return (0);
	}
	cup->f_str = 0;
	cup->l_str = 0;
	cup->indx = 0;
	return (cup);
}

int		ft_overflow(va_list argue, t_bist *cup)
{
	t_pist	*jar;
	size_t	count;

	jar = NULL;
	count = 0;
	jar = ft_initial_h(jar);
	ft_flag_handle(jar, argue, cup);
	count += jar->count;
	free(jar);
	return (count);
}

int		ft_start(va_list argue, const char *format)
{
	t_bist	*cup;
	size_t	count;

	cup = NULL;
	count = 0;
	cup = ft_initial_f(cup);
	cup->f_str = format;
	while (*(cup->f_str) != '\0')
	{
		if (*(cup->f_str) == '%')
		{
			cup->f_str++;
			if (!(*cup->f_str))
				break ;
			count += ft_overflow(argue, cup);
		}
		else
		{
			ft_putchar(*(cup->f_str));
			count++;
			cup->f_str++;
		}
	}
	free(cup);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list	argue;
	size_t	count;

	count = 0;
	if (format)
	{
		va_start(argue, format);
		count = ft_start(argue, format);
		va_end(argue);
	}
	return (count);
}
