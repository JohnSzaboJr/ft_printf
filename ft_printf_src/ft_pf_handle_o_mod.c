/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_o_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/24 18:58:44 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_handle_o_mod(char **new, char **str, char **spaces, t_print *features)
{
  if (!(*new = ft_strdup(*str)) ||
      !ft_pf_precision_num(new, features) ||
      !ft_pf_width_fl_zeros_left(new, spaces, features)) 
	return (0);
  return (1);
}

int     ft_pf_handle_no_o(va_list args, t_print *features, int *ret)
{
    unsigned int	c;
    char			*str;
    char			*new;
    char			*spaces;

    c = (va_arg(args, unsigned int));
    str = ft_uitoa_base(c, 8);
    if (!(ft_pf_handle_o_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}

int		ft_pf_handle_hh_o(va_list args, t_print *features, int *ret)
{
	unsigned char	c;
	char		*str;
	char		*new;
	char		*spaces;

	c = (unsigned char)(va_arg(args, unsigned long long));
	str = ft_uitoa_base(c, 8);
	if (!(ft_pf_handle_o_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);  
}

int		ft_pf_handle_h_o(va_list args, t_print *features, int *ret)
{
    unsigned short   c;
    char			*str;
    char			*new;
    char			*spaces;

    c = (unsigned short)(va_arg(args, unsigned long long));
    str = ft_uitoa_base(c, 8);
    if (!(ft_pf_handle_o_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}

int		ft_pf_handle_ll_o(va_list args, t_print *features, int *ret)
{
	unsigned long long	c;
	char				*str;
    char				*new;
    char				*spaces;

    c = va_arg(args, unsigned long long);
    str = ft_uitoa_base(c, 8);
    if (!(ft_pf_handle_o_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}
