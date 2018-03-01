/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_d_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/20 15:36:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_handle_d_mod(char **new, char **str, char **spaces, t_print *features)
{
  if (!(*new = ft_strdup(*str)) ||
      !ft_pf_plus_space(new, features) ||
      !ft_pf_precision_num(new, features) ||
      !ft_pf_width_fl_zeros_left(new, spaces, features) ||
      !ft_pf_sign(new, features))
	return (0);
  return (1);
}

int     ft_pf_handle_hh_d(va_list args, t_print *features, int *ret)
{
	signed char	c;
	char		*str;
	char		*new;
	char		*spaces;

	c = (signed char)(va_arg(args, long long int));
	str = ft_itoa(c);
	if (!(ft_pf_handle_d_mod(&new, &str, &spaces, features)))
	  return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
	free(str);
    return (1);  
}

int     ft_pf_handle_h_d(va_list args, t_print *features, int *ret)
{
  short		c;
  char            *str;
  char            *new;
  char            *spaces;

  c = (short)(va_arg(args, long long int));
  str = ft_itoa(c);
  if (!(ft_pf_handle_d_mod(&new, &str, &spaces, features)))
    return (0);
  ft_putstr(new);
  *ret = *ret + ft_strlen(new);
  free(new);
  free(str);
  return (1);
}

int     ft_pf_handle_ll_d(va_list args, t_print *features, int *ret)
{
  long long         c;
  char            *str;
  char            *new;
  char            *spaces;

  c = (va_arg(args, long long));
  str = ft_longlongtoa(c);
  if (!(ft_pf_handle_d_mod(&new, &str, &spaces, features)))
    return (0);
  ft_putstr(new);
  *ret = *ret + ft_strlen(new);
  free(new);
  free(str);
  return (1);
}

int     ft_pf_handle_l_d(va_list args, t_print *features, int *ret)
{
  long         c;
  char            *str;
  char            *new;
  char            *spaces;

  c = (long int)(va_arg(args, long long int));
  str = ft_longtoa(c);
  if (!(ft_pf_handle_d_mod(&new, &str, &spaces, features)))
    return (0);
  ft_putstr(new);
  *ret = *ret + ft_strlen(new);
  free(new);
  free(str);
  return (1);
}
