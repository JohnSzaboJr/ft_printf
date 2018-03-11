/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_f_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/11 14:33:33 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_handle_f_mod(char **new, char **str, char **spaces, t_print *features)
{
  if (!(*new = ft_strdup(*str)) ||
      !ft_pf_plus_space(new, features) ||
      !ft_pf_width_fl_zeros_left(new, spaces, features) ||
      !ft_pf_sign(new, features))
	return (0);
  return (1);
}

int     ft_pf_handle_no_f(va_list args, t_print *features, int *ret)
{
    double      c;
    char        *str;
    char        *new;
    char        *spaces;
	size_t		pr;

	if (!(features->is_precision))
		pr = 6;
	else
		pr = features->precision;
    c = (va_arg(args, double));
    str = ft_ftoa(c, pr);
    if (!(ft_pf_handle_f_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}

int     ft_pf_handle_ll_f(va_list args, t_print *features, int *ret)
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
