/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_u_mod_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/14 15:20:28 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_l_u(va_list args, t_print *features, int *ret)
{
	unsigned long		c;
	char				*str;
	char				*new;
	char				*spaces;

	c = va_arg(args, unsigned long);
	str = ft_uitoa_base(c, 10);
	if (!(ft_pf_handle_u_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}

int		ft_pf_handle_j_u(va_list args, t_print *features, int *ret)
{
	uintmax_t		c;
	char			*str;
	char			*new;
	char			*spaces;

	c = va_arg(args, uintmax_t);
	str = ft_uitoa_base(c, 10);
	if (!(ft_pf_handle_u_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}

int		ft_pf_handle_z_u(va_list args, t_print *features, int *ret)
{
	size_t		c;
	char		*str;
	char		*new;
	char		*spaces;

	c = va_arg(args, size_t);
	str = ft_uitoa_base(c, 10);
	if (!(ft_pf_handle_u_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);
}
