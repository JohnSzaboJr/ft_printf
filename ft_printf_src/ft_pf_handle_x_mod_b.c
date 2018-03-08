/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_x_mod_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/08 15:48:36 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_l_x(va_list args, t_print *features, int *ret)
{
	unsigned long		c;
	char				*str;
	char				*new;
	char				*spaces;

	c = va_arg(args, unsigned long);
	str = ft_uitoa_base(c, 16);
	if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}

int		ft_pf_handle_j_x(va_list args, t_print *features, int *ret)
{
	uintmax_t			c;
	char				*str;
	char				*new;
	char				*spaces;

	c = va_arg(args, uintmax_t);
	str = ft_uitoa_base(c, 16);
	if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}

int		ft_pf_handle_z_x(va_list args, t_print *features, int *ret)
{
	size_t				c;
	char				*str;
	char				*new;
	char				*spaces;

	c = va_arg(args, size_t);
	str = ft_uitoa_base(c, 16);
	if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}
