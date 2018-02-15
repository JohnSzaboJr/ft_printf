/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:03:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 13:22:48 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_width_fl_zeros_left(char **str, char **spaces, t_print *features)
{
	char *tmp;

	tmp = NULL;
	if (features->width > ft_strlen(*str))
	{
		if (!((*spaces) = ft_strnew(features->width - ft_strlen(*str))))
			return (0);
		if (features->fl_prep_zeros)
			*spaces = ft_strnfill(*spaces, '0', (features->width - ft_strlen(*str)));
		else
			*spaces = ft_strnfill(*spaces, ' ', (features->width - ft_strlen(*str)));
		if (!ft_strlen(*str))
			tmp = ft_strdup(*spaces);
		else if (features->fl_left_just && !(tmp = ft_strjoin(*str, *spaces)))
			return (0);
		else if (!(features->fl_left_just) && !(tmp = ft_strjoin(*spaces, *str)))
			return (0);
		free(*str);
		free(*spaces);
		if (!(*str = ft_strdup(tmp)))
			return (0);
		free(tmp);
	}
	return (1);
}
