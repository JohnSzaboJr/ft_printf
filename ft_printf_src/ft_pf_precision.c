/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:52:42 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/20 13:39:30 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_precision_s(char **str, t_print *features)
{
  if (features->is_precision && ft_strlen(*str) > features->precision)
		(*str)[features->precision] = '\0';
	return (1);
}

int     ft_pf_precision_cap_s(wchar_t **str, t_print *features)
{
  if (features->is_precision && ft_wstrlen(*str) > (int)(features->precision))
    (*str)[features->precision] = L'\0';
  return (1);
}

int     ft_pf_precision_num(char **str, t_print *features)
{
  char *spaces;
  char *new;

  if (features->precision > ft_strlen(*str))
    {
      if (!(spaces = ft_strnew(features->precision - ft_strlen(*str))))
		  return (0);
      spaces = ft_strnfill(spaces, '0', (features->precision - ft_strlen(*str)));
      if (!(new = ft_strjoin(spaces, *str)))
		  return (0);
      free(spaces);
      free(*str);
      *str = new;
    }
  if (features->is_precision)
    features->fl_prep_zeros = 0;
  return (1);
}
