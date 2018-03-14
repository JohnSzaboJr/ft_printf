/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/14 15:26:12 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_d(va_list args, t_print *features, int *ret)
{
	if (!(features->mod) && !ft_pf_handle_no_d(args, features, ret))
		return (0);
	if (features->mod == 'H' && !ft_pf_handle_hh_d(args, features, ret))
		return (0);
	if (features->mod == 'h' && !ft_pf_handle_h_d(args, features, ret))
		return (0);
	if (features->mod == 'L' && !ft_pf_handle_ll_d(args, features, ret))
		return (0);
	if (features->mod == 'l' && !ft_pf_handle_l_d(args, features, ret))
		return (0);
	if (features->mod == 'j' && !ft_pf_handle_j_d(args, features, ret))
		return (0);
	if (features->mod == 'z' && !ft_pf_handle_z_d(args, features, ret))
		return (0);
	return (1);
}

int		ft_pf_handle_o(va_list args, t_print *features, int *ret)
{
	if (!(features->mod) && !ft_pf_handle_no_o(args, features, ret))
		return (0);
	if (features->mod == 'H' && !ft_pf_handle_hh_o(args, features, ret))
		return (0);
	if (features->mod == 'h' && !ft_pf_handle_h_o(args, features, ret))
		return (0);
	if (features->mod == 'L' && !ft_pf_handle_ll_o(args, features, ret))
		return (0);
	if (features->mod == 'l' && !ft_pf_handle_l_o(args, features, ret))
		return (0);
	if (features->mod == 'j' && !ft_pf_handle_j_o(args, features, ret))
		return (0);
	if (features->mod == 'z' && !ft_pf_handle_z_o(args, features, ret))
		return (0);
	return (1);
}

int		ft_pf_handle_u(va_list args, t_print *features, int *ret)
{
	if (!(features->mod) && !ft_pf_handle_no_u(args, features, ret))
		return (0);
	if (features->mod == 'H' && !ft_pf_handle_hh_u(args, features, ret))
		return (0);
	if (features->mod == 'h' && !ft_pf_handle_h_u(args, features, ret))
		return (0);
	if (features->mod == 'L' && !ft_pf_handle_ll_u(args, features, ret))
		return (0);
	if (features->mod == 'l' && !ft_pf_handle_l_u(args, features, ret))
		return (0);
	if (features->mod == 'j' && !ft_pf_handle_j_u(args, features, ret))
		return (0);
	if (features->mod == 'z' && !ft_pf_handle_z_u(args, features, ret))
		return (0);
	return (1);
}

int		ft_pf_handle_x(va_list args, t_print *features, int *ret)
{
	if (!(features->mod) && !ft_pf_handle_no_x(args, features, ret))
		return (0);
	if (features->mod == 'H' && !ft_pf_handle_hh_x(args, features, ret))
		return (0);
	if (features->mod == 'h' && !ft_pf_handle_h_x(args, features, ret))
		return (0);
	if (features->mod == 'L' && !ft_pf_handle_ll_x(args, features, ret))
		return (0);
	if (features->mod == 'l' && !ft_pf_handle_l_x(args, features, ret))
		return (0);
	if (features->mod == 'j' && !ft_pf_handle_j_x(args, features, ret))
		return (0);
	if (features->mod == 'z' && !ft_pf_handle_z_x(args, features, ret))
		return (0);
	return (1);
}

int		ft_pf_handle_f(va_list args, t_print *features, int *ret)
{
	if (!(features->mod) && !ft_pf_handle_no_f(args, features, ret))
		return (0);
	if (features->mod == 'L' && !ft_pf_handle_ll_f(args, features, ret))
		return (0);
	return (1);
}
