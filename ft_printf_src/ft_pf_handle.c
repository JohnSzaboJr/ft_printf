/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/20 13:41:24 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_handle_percent(int *ret)
{
	ft_putchar('%');
	(*ret)++;
	return (1);
}

int	ft_pf_handle_strings(int *ret, va_list args, t_print *features)
{
  if (features->type == 's' && features->mod != 'l' && !(ft_pf_handle_s(args, features, ret)))
	return (0);
  if (features->type == 's' && features->mod == 'l' && !(ft_pf_handle_cap_s(args, features, ret)))
    	return (0);
  if (features->type == 'S' && !ft_pf_handle_cap_s(args, features, ret))
	return (0);
	return (1);
}

int	ft_pf_handle_pointers(int *ret, va_list args, t_print *features)
{
  size_t	ptr;
  char		*str;
  char		*new;
  char		*spaces;

  ptr = (size_t)(va_arg(args, void*));
  str = ft_sizettohexa(ptr);
  if (!(new = ft_strdup(str)) ||
      !ft_pf_precision_num(&new, features) ||
      !ft_pf_hex_sign(&new) ||
      !ft_pf_width_fl_zeros_left(&new, &spaces, features) ||
      !ft_pf_hex_sign_zeros(&new))
    return (0);
  free(str);
  ft_putstr(new);
  *ret = *ret + ft_strlen(new);
  free(new);
  return (1);
}

int     ft_pf_handle_numbers(int *ret, va_list args, t_print *features)
{
  if (features->type == 'd' && !ft_pf_handle_d(args, features, ret))
    return (0);
  if (features->type == 'i' && !ft_pf_handle_d(args, features, ret))
    return (0);
  if (features->type == 'D' && !ft_pf_handle_l_d(args, features, ret))
    return (0);
  return (1);
}
