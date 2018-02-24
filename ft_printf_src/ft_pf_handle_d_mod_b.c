/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_d_mod_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/20 15:36:37 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int     ft_pf_handle_j_d(va_list args, t_print *features, int *ret)
{
	intmax_t	c;
	char		*str;
	char		*new;
	char		*spaces;

	c = (va_arg(args, intmax_t));
	str = ft_intmaxtoa(c);
	if (!(ft_pf_handle_d_mod(&new, &str, &spaces, features)))
	  return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
	free(str);
    return (1);  
}

int     ft_pf_handle_z_d(va_list args, t_print *features, int *ret)
{
  long long		c;
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
