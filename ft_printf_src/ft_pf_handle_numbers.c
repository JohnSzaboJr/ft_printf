/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/20 13:53:55 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int     ft_pf_handle_d(va_list args, t_print *features, int *ret)
{
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
