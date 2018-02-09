/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:59:10 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/09 14:54:44 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

//
#include <stdio.h>

int	ft_printf(char *format, ... )
{
	va_list args;
	int		l;
	char	*out;

	out = NULL;
	va_start(args, format);
	l = ft_strchlen(format, '%');
	if (l < 0)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else if (l > 0)
	{
		out = ft_strnew(l);
		out = ft_strncpy(out, format, l);
	}
	ft_putstr(out);
	free(out);

// if no double % then...
// add a struct (t_print)
// parse through flags and whatnot, and save in the struct
// when the end of the flags is reached, format the first arg accordingly
// (make a new string)
// ft_strjoin <- new
// then start again in a loop...
	
// ==================================
//	char *str = va_arg(args, char *);
// are too many args simply ignored?

	va_end(args);
	return (1);
}
