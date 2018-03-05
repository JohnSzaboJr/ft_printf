/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/24 11:22:08 by jszabo           ###   ########.fr       */
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
  if (features->type == 'o' && !ft_pf_handle_o(args, features, ret))
	  return (0);
  if (features->type == 'O' && !ft_pf_handle_l_o(args, features, ret))
    return (0);
  if (features->type == 'u' && !ft_pf_handle_u(args, features, ret))
    return (0);
  if (features->type == 'U' && !ft_pf_handle_l_u(args, features, ret))
    return (0);
  if (features->type == 'x' && !ft_pf_handle_x(args, features, ret))
    return (0);
  if (features->type == 'X' && !ft_pf_handle_x(args, features, ret))
    return (0);
  return (1);
}

int     ft_pf_handle_chars(int *ret, va_list args, t_print *features)
{
  if (features->type == 'c' && features->mod != 'l' && !(ft_pf_handle_c(args, features, ret)))
    return (0);
  if (features->type == 'c' && features->mod == 'l' && !(ft_pf_handle_cap_c(args, features, ret)))
    return (0);
  if (features->type == 'C' && !ft_pf_handle_cap_c(args, features, ret))
    return (0);
  return (1);
}
