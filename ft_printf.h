/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:13:26 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 13:23:26 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_struct
{
	int		fl_left_just;
	int		fl_signed_num;
	int		fl_sign_space;
	int		fl_prep_zeros;
	int		fl_alter;
	size_t	width;
	size_t	precision;
	int		mod_hh;
	int		mod_ll;
	int		mod_h;
	int		mod_l;
	int		mod_j;
	int		mod_z;
	char	type;
}				t_print;

int		ft_pf_store_flags(char **str, t_print *features);
int		ft_pf_store_num_width(char **str, size_t *target, va_list args);
int		ft_pf_store_precision(char **str, size_t *target, va_list args);
int		ft_pf_store_modifiers(char **str, t_print *features);
int		ft_pf_store_type(char **str, char *type);
int		ft_pf_handle_percent(int *ret);
int		ft_pf_handle_strings(int *ret, va_list args, t_print *features);
int		ft_pf_struct_init(t_print *features);
int		ft_pf_precision_s(char **str, size_t precision);
int		ft_pf_width_fl_zeros_left(char **str, char **spaces, t_print *features);

#endif
