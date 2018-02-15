/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:59:10 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 10:27:43 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_pf_format(t_print *features, va_list args, int *ret)
{
	char t;

	t = features->type;
	if (t == '%')
		return (ft_pf_handle_percent(ret));
	if (t == 'S' || t == 's')
		return (ft_pf_handle_strings(ret, args, features));
	return (1);
}

static int	ft_pf_symbols(char **str, int *ret, va_list args)
{
	t_print		*features;

	if (!(features = (t_print *)malloc(sizeof(*features))) ||
		ft_strlen(*str) == 1 ||
		!ft_pf_struct_init(features) ||
		!ft_stroneleft(str) ||
		!ft_pf_store_flags(str, features) ||
		!ft_pf_store_num_width(str, &(features->width), args) ||
		!ft_pf_store_precision(str, &(features->precision), args) ||
		!ft_pf_store_modifiers(str, features) || 
		!ft_pf_store_type(str, &(features->type)) ||
		!ft_pf_format(features, args, ret))
		return (0);
	free(features);
	return (1);
}

int			ft_printf(char *format, ... )
{
	va_list args;
	int		ret;
	char	*out;
	char	*str;

	out = NULL;
	ret = 0;
	if (!(str = ft_strdup(format)))
		return (-1);
	va_start(args, format);
	while (str[0])
	{
		if (ft_strchlen(str, '%') < 0)
		{
			ft_putstr(str);
			ret = ret + ft_strlen(str);
			free(str);
			return (ret);
		}
		if (ft_strchlen(str, '%') > 0)
		{
			if (!(out = ft_strdiv(&str, out, ft_strchlen(str, '%'))))
				return (-1);
			ft_putstr(out);
			ret = ret + ft_strlen(out);
			free(out);
		}
		else
		{
			if (!ft_pf_symbols(&str, &ret, args))
				return (-1);
		}
	}

// format accordingly
// (make a new string)
// ft_strjoin <- new
// then start again in a loop...
	
// ================================?
// when does it return a neg number or 0?
// strchr

	va_end(args);
	return (ret);
}
