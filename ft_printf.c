/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:59:10 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/12 17:06:07 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_pf_symbols(char **str, int *ret, va_list args)
{
	t_print		*features;
	char		*new;

	if (!(features = (t_print *)malloc(sizeof(*features))))
		return (0);
	ft_pf_store_flags(str, features);
	ft_pf_store_num_width(str, &(features->width), args);
	ft_pf_store_precision(str, &(features->precision), args);
	if (!ft_pf_store_modifiers(str, features))
		return (0);

	(*ret)++;
	new = ft_itoa(va_arg(args, int));
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
	str = ft_strdup(format);
	va_start(args, format);

	while (str[0])
	{
		if (ft_strchlen(str, '%') < 0)
		{
			ft_putstr(str);
			return (ret + ft_strlen(str));
		}
		if (ft_strchlen(str, '%') > 0)
		{
			if (!(out = ft_strdiv(&str, out, ft_strchlen(str, '%'))))
				return (-1);
			ft_putstr(out);
			ret = ret + ft_strlen(out);
			free(out);
		}
		if (str[1] && str[1] == '%')
		{
			ft_putchar('%');
			ret++;
			str = ft_memmove(str, str + 2, ft_strlen(str) - 1);
		}
		else
		{
			if (!ft_pf_symbols(&str, &ret, args))
				return (-1);
		}
	}

// parse through flags and whatnot, and save in the struct
// when the end of the flags is reached, format the first arg accordingly
// (make a new string)
// ft_strjoin <- new
// then start again in a loop...
	
// ================================?
// handle when last character is %
// when does it return a neg number or 0?
// strchr

	va_end(args);
	return (ret);
}
