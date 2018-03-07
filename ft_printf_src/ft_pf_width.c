/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:03:32 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/07 16:15:43 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_width_fl_zeros_left(char **str, char **spaces, t_print *features)
{
	char	*tmp;

	tmp = NULL;
	if (features->width > ft_strlen(*str))
	{
		if (!((*spaces) = ft_strnew(features->width - ft_strlen(*str))))
			return (0);
		if (features->fl_prep_zeros)
			*spaces = ft_strnfill(*spaces, '0',
	(features->width - ft_strlen(*str)));
		else
			*spaces = ft_strnfill(*spaces, ' ',
	(features->width - ft_strlen(*str)));
		if (!ft_strlen(*str))
			tmp = ft_strdup(*spaces);
		else if (features->fl_left_just &&
	!(tmp = ft_strjoin(*str, *spaces)))
			return (0);
		else if (!(features->fl_left_just) &&
	!(tmp = ft_strjoin(*spaces, *str)))
			return (0);
		free(*str);
		free(*spaces);
		*str = tmp;
	}
	return (1);
}

int	ft_pf_width_fl_zeros_left_null_c(char **spaces, t_print *features)
{
	if (features->width > 1)
	{
		if (!((*spaces) = ft_strnew(features->width - 1)))
			return (0);
		if (features->fl_prep_zeros)
			*spaces = ft_strnfill(*spaces, '0',
	(features->width - 1));
		else
			*spaces = ft_strnfill(*spaces, ' ',
	(features->width - 1));
		if (features->fl_left_just)
		{
			write(1, "\0", 1);
			ft_putstr(*spaces);
		}
		else
		{
			ft_putstr(*spaces);
			write(1, "\0", 1);
		}
	}
	else
	{
		if (!((*spaces) = ft_strnew(0)))
			return (0);
		write(1, "\0", 1);
	}
	return (1);
}

int	ft_pf_width_fl_zeros_left_cap_s
	(wchar_t **str, wchar_t **spaces, t_print *features)
{
	wchar_t *tmp;

	tmp = NULL;
	if ((int)features->width > ft_wstrlen(*str))
	{
		if (!((*spaces) = ft_wstrnew((int)features->width - ft_wstrlen(*str))))
			return (0);
		if (features->fl_prep_zeros)
			*spaces = ft_wstrnfill(*spaces, L'0',
	((int)features->width - ft_wstrlen(*str)));
		else
			*spaces = ft_wstrnfill(*spaces, L' ',
	((int)features->width - ft_wstrlen(*str)));
		if (!ft_wstrlen(*str))
			tmp = ft_wstrdup(*spaces);
		else if (features->fl_left_just &&
	!(tmp = ft_wstrjoin(*str, *spaces)))
			return (0);
		else if (!(features->fl_left_just) &&
	!(tmp = ft_wstrjoin(*spaces, *str)))
			return (0);
		free(*str);
		free(*spaces);
		if (!(*str = ft_wstrdup(tmp)))
			return (0);
		free(tmp);
	}
	return (1);
}
