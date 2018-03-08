/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:13:26 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/08 16:20:15 by jszabo           ###   ########.fr       */
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
  int		is_precision;
	char		mod;
	char	type;
}				t_print;

int		ft_pf_store_flags(char **str, t_print *features);
int		ft_pf_store_num_width(char **str, size_t *target, va_list args, t_print *features);
int		ft_pf_store_precision(char **str, t_print *features, va_list args);
int		ft_pf_store_modifiers(char **str, t_print *features);
int		ft_pf_store_type(char **str, char *type);
int		ft_pf_handle_strings(int *ret, va_list args, t_print *features);
int		ft_pf_handle_pointers(int *ret, va_list args, t_print *features);
int		ft_pf_handle_numbers(int *ret, va_list args, t_print *features);
int		ft_pf_struct_init(t_print *features);
int		ft_pf_precision_s(char **str, t_print *features);
int		ft_pf_precision_cap_s(wchar_t **str, t_print *features);
int		ft_pf_precision_num(char **str, t_print *features);
int		ft_pf_width_fl_zeros_left(char **str, char **spaces, t_print *features);
int		ft_pf_width_fl_zeros_left_cap_s(wchar_t **str, wchar_t **spaces, t_print *features);
int		ft_pf_handle_s(va_list args, t_print *features, int *ret);
int		ft_pf_handle_cap_s(va_list args, t_print *features, int *ret);
int		ft_pf_handle_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_d_mod(char **new, char **str, char **spaces, t_print *features);
int		ft_pf_handle_no_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_hh_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_h_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_ll_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_l_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_j_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_z_d(va_list args, t_print *features, int *ret);
int		ft_pf_handle_o(va_list args, t_print *features, int *ret);
int		ft_pf_handle_o_mod(char **new, char **str, char **spaces, t_print *features);
int		ft_pf_handle_no_o(va_list args, t_print *features, int *ret);
int     ft_pf_handle_hh_o(va_list args, t_print *features, int *ret);
int		ft_pf_handle_h_o(va_list args, t_print *features, int *ret);
int		ft_pf_handle_ll_o(va_list args, t_print *features, int *ret);
int             ft_pf_handle_l_o(va_list args, t_print *features, int *ret);
int             ft_pf_handle_j_o(va_list args, t_print *features, int *ret);
int             ft_pf_handle_z_o(va_list args, t_print *features, int *ret);
int             ft_pf_handle_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_u_mod(char **new, char **str, char **spaces, t_print *features);
int             ft_pf_handle_no_u(va_list args, t_print *features, int *ret);
int     ft_pf_handle_hh_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_h_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_ll_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_l_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_j_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_z_u(va_list args, t_print *features, int *ret);
int             ft_pf_handle_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_x_mod(char **new, char **str, char **spaces, t_print *features);
int             ft_pf_handle_no_x(va_list args, t_print *features, int *ret);
int     ft_pf_handle_hh_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_h_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_ll_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_l_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_j_x(va_list args, t_print *features, int *ret);
int             ft_pf_handle_z_x(va_list args, t_print *features, int *ret);
int		ft_pf_hex_sign(char **str);
int		ft_pf_hex_sign_zeros(char **str);
int		ft_pf_sign(char **str, t_print *features);
int		ft_pf_plus_space(char **str, t_print *features);
int		ft_pf_alter(char **str, int alter);
int		ft_pf_alter_x(char **str, t_print *features);
int		ft_pf_alter_x_final(char **str, t_print *features);
int		ft_pf_handle_chars(int *ret, va_list args, t_print *features);
int             ft_pf_handle_c(va_list args, t_print *features, int *ret);
int             ft_pf_handle_cap_c(va_list args, t_print *features, int *ret);
int		ft_pf_width_fl_zeros_left_null_c(char **spaces, t_print *features);
int     ft_pf_handle_others(t_print *features, int *ret);

#endif
