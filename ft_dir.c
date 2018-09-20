/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 07:21:00 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:23:33 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_int_dir(t_pist *jar, va_list argue)
{
	if (jar->len_m == 4 || jar->len_m == 5)
		ft_print_s(va_arg(argue, intmax_t), jar);
	else if (jar->len_m == 1)
		ft_print_s(va_arg(argue, long long), jar);
	else if (jar->len_m == 3 || jar->con_c == 'D')
		ft_print_s(va_arg(argue, long), jar);
	else if (jar->len_m == 6)
		ft_print_s((char)va_arg(argue, int), jar);
	else if (jar->len_m == 2)
		ft_print_s((short)va_arg(argue, int), jar);
	else
		ft_print_s(va_arg(argue, int), jar);
	return ;
}

void	ft_uint_dir(t_pist *jar, va_list argue)
{
	if (jar->len_m == 4)
		ft_print_u(va_arg(argue, uintmax_t), jar, 10);
	else if (jar->len_m == 5)
		ft_print_u(va_arg(argue, size_t), jar, 10);
	else if (jar->len_m == 1)
		ft_print_u(va_arg(argue, unsigned long long), jar, 10);
	else if (jar->len_m == 3 || jar->con_c == 'U')
		ft_print_u(va_arg(argue, unsigned long), jar, 10);
	else if (jar->len_m == 6)
		ft_print_u((unsigned char)va_arg(argue, unsigned int), jar, 10);
	else if (jar->len_m == 2)
		ft_print_u((unsigned short)va_arg(argue, unsigned int), jar, 10);
	else
		ft_print_u(va_arg(argue, unsigned int), jar, 10);
	return ;
}

void	ft_hex_dir(t_pist *jar, va_list argue)
{
	if (jar->con_c == 'p')
		ft_print_u((uintmax_t)va_arg(argue, void *), jar, 16);
	else if (jar->len_m == 4)
		ft_print_u(va_arg(argue, uintmax_t), jar, 16);
	else if (jar->len_m == 5)
		ft_print_u(va_arg(argue, size_t), jar, 16);
	else if (jar->len_m == 1)
		ft_print_u(va_arg(argue, unsigned long long), jar, 16);
	else if (jar->len_m == 3)
		ft_print_u(va_arg(argue, unsigned long), jar, 16);
	else if (jar->len_m == 2)
		ft_print_u((unsigned short)va_arg(argue, unsigned int), jar, 16);
	else if (jar->len_m == 6)
		ft_print_u((unsigned char)va_arg(argue, unsigned int), jar, 16);
	else
		ft_print_u(va_arg(argue, unsigned int), jar, 16);
	return ;
}

void	ft_oct_dir(t_pist *jar, va_list argue)
{
	if (jar->len_m == 4)
		ft_print_u(va_arg(argue, uintmax_t), jar, 8);
	else if (jar->len_m == 5)
		ft_print_u(va_arg(argue, size_t), jar, 8);
	else if (jar->len_m == 1)
		ft_print_u(va_arg(argue, unsigned long long), jar, 8);
	else if (jar->len_m == 3 || jar->con_c == 'O')
		ft_print_u(va_arg(argue, unsigned long), jar, 8);
	else if (jar->len_m == 2)
		ft_print_u((unsigned short)va_arg(argue, unsigned int), jar, 8);
	else if (jar->len_m == 6)
		ft_print_u((unsigned char)va_arg(argue, unsigned int), jar, 8);
	else
		ft_print_u(va_arg(argue, unsigned int), jar, 8);
	return ;
}
