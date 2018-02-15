/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 15:53:08 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_handle_percent(int *ret)
{
	ft_putchar('%');
	(*ret)++;
	return (1);
}

int	ft_pf_handle_strings(int *ret, va_list args, t_print *features)
{
	char 	*str;
	char 	*new;
	char 	*spaces;
	wchar_t *str_t;
	wchar_t	*new_t;

	if (features->type == 'S')
	{
		str_t = va_arg(args, wchar_t*);
		ft_putwstr(str_t);
	}
	if (features->type == 's')
	{
		str = va_arg(args, char*);
		if (!(new = ft_strdup(str)))
			return (0);
		if (!ft_pf_precision_s(&new, features->precision) ||
			!ft_pf_width_fl_zeros_left(&new, &spaces, features))
			return (0);
		ft_putstr(new);
		ret = ret + ft_strlen(new);
		free(new);
	}
	// put string handling functions into 2 separate, and in sep file
	return (1);
}
