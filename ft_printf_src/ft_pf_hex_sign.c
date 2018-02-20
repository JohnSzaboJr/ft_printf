/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 15:53:08 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_hex_sign(char **str)
{
  const char	*hex = "0x";
  char		*tmp;

  if (!(tmp = ft_strjoin(hex, *str)))
    return (0);
  free(*str);
  *str = tmp;
  return (1);
}

int     ft_pf_hex_sign_zeros(char **str)
{
  if ((*str)[1] == '0')
    {
      *(ft_strchr(*str, 'x')) = '0';
      (*str)[1] = 'x';
    }
  return (1);
}
