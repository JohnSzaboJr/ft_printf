/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:13:26 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/12 17:03:17 by jszabo           ###   ########.fr       */
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
	int		width;
	int		precision;
	char	*modifiers;
}				t_print;

void ft_pf_store_flags(char **str, t_print *features);
void ft_pf_store_num_width(char **str, int *target, va_list args);
void ft_pf_store_precision(char **str, int *target, va_list args);
int  ft_pf_store_modifiers(char **str, t_print *features);

#endif
