/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exabanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:06:49 by exabanis          #+#    #+#             */
/*   Updated: 2018/09/20 16:24:46 by exabanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft/libft.h"
# define CONV_C	"cCdDioOpsSuUxX"
# define FLAGS	"#+ 0-"
# define MOD	"hljz"
# define ZERO	"0"

typedef struct	s_pist
{
	char		*oh_prex;
	char		*zeros;
	char		*spaces;
	char		con_c;
	int			flag0;
	int			flag1;
	int			flag2;
	int			flag3;
	int			flag4;
	int			len_m;
	int			max_w;
	int			min_w;
	int			h;
	int			p;
	size_t		count;
}				t_pist;

typedef struct	s_bist
{
	const char	*f_str;
	char		*l_str;
	int			indx;
}				t_bist;

char			*ft_itoa_b(uintmax_t n);
char			*ft_put_space(t_pist *jar, char *str);
char			*ft_put_zero(t_pist *jar, char *str);
char			*ft_utoa_base(uintmax_t n, int base);

int				ft_printf(const char *format, ...);
int				ft_wclen(wchar_t w_char);

size_t			ft_wstrlen(wchar_t *str);

void			ft_int_dir(t_pist *jar, va_list argue);
void			ft_uint_dir(t_pist *jar, va_list argue);
void			ft_hex_dir(t_pist *jar, va_list argue);
void			ft_oct_dir(t_pist *jar, va_list argue);
void			ft_prefix(t_pist *jar, uintmax_t n);
void			ft_print_char(t_pist *jar, char c);
void			ft_print_s(intmax_t n, t_pist *jar);
void			ft_print_str(t_pist *jar, char *str);
void			ft_print_u(uintmax_t n, t_pist *jar, int base);
void			ft_print_wstr(t_pist *jar, wchar_t *str);
void			ft_print_wchar(t_pist *jar, wchar_t c);
void			ft_put_sign(t_pist *jar, intmax_t n);
void			ft_space(t_pist *jar);
void			ft_wchar(t_pist *jar, wchar_t c);
void			ft_wstr(t_pist *jar, wchar_t *str);
void			ft_flag_handle(t_pist *jar, va_list argue, t_bist *cup);
void			ft_convert(t_pist *jar, va_list argue, char c);

#endif
