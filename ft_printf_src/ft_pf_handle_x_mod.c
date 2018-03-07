/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_x_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/07 12:18:17 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_handle_x_mod(char **new, char **str, char **spaces, t_print *features)
{
	int i;

	i = 0;
	if (!(*new = ft_strdup(*str)) ||
	!ft_pf_precision_num(new, features) ||
	!ft_pf_alter_x(new, features) ||
	!ft_pf_width_fl_zeros_left(new, spaces, features) ||
	!ft_pf_alter_x_final(new, features)) 
		return (0);
	while ((*new)[i] && features->type == 'x')
	{
		(*new)[i] = ft_tolower((*new)[i]); 
		i++;
	}
	return (1);
}

int     ft_pf_handle_no_x(va_list args, t_print *features, int *ret)
{
    unsigned int	c;
    char			*str;
    char			*new;
    char			*spaces;

    c = (va_arg(args, unsigned int));
    str = ft_uitoa_base(c, 16);
    if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}

int		ft_pf_handle_hh_x(va_list args, t_print *features, int *ret)
{
	unsigned char	c;
	char		*str;
	char		*new;
	char		*spaces;

	c = (unsigned char)(va_arg(args, unsigned long long));
	str = ft_uitoa_base(c, 16);
	if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
		return (0);
	ft_putstr(new);
	*ret = *ret + ft_strlen(new);
	free(new);
	free(str);
	return (1);  
}

int		ft_pf_handle_h_x(va_list args, t_print *features, int *ret)
{
    unsigned short   c;
    char			*str;
    char			*new;
    char			*spaces;

    c = (unsigned short)(va_arg(args, unsigned long long));
    str = ft_uitoa_base(c, 16);
    if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}

int		ft_pf_handle_ll_x(va_list args, t_print *features, int *ret)
{
	unsigned long long	c;
	char				*str;
    char				*new;
    char				*spaces;

    c = va_arg(args, unsigned long long);
    str = ft_uitoa_base(c, 16);
    if (!(ft_pf_handle_x_mod(&new, &str, &spaces, features)))
        return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    free(str);
    return (1);
}
