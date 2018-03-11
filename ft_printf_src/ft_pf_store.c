/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:53:24 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/11 09:49:38 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_store_type(char **str, char *type)
{
	*type = (*str)[0];
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}

int		ft_pf_store_flags(char **str, t_print *features)
{
	const char	*flags = "-+ 0#";
	int			i;

	i = 0;
	if (!((*str)[0]))
		return (1);
	while ((*str)[i] && ft_strchr(flags, (*str)[i]))
	{
		if ((*str)[i] == '0' && !(features->fl_left_just))
			features->fl_prep_zeros = 1;
		if ((*str)[i] == ' ' && !(features->fl_signed_num))
			features->fl_sign_space = 1;
		if ((*str)[i] == '#')
			features->fl_alter = 1;
		if ((*str)[i] == '+')
		{
			features->fl_signed_num = 1;
			features->fl_sign_space = 0;
		}
		if ((*str)[i] == '-')
		{
			features->fl_left_just = 1;
			features->fl_prep_zeros = 0;
		}
		i++;
	}
	*str = ft_memmove(*str, *str + i, ft_strlen(*str) - i + 1);
	return (1);
}

int		ft_pf_store_num_width(char **str, size_t *target, va_list args,
	t_print *features)
{
	int num;

	num = 0;
	if (!((*str)[0]))
		return (1);
	if (ft_isdigit((*str)[0]))
	{
		*target = ft_atoi(*str);
		*str = ft_memmove(*str, *str + ft_numlen(*target),
	ft_strlen(*str) - ft_numlen(*target) + 1);
	}
	else if ((*str)[0] == '*')
	{
		num = va_arg(args, int);
		if (num < 0)
		{
			features->fl_left_just = 1;
			features->fl_prep_zeros = 0;
			num = -num;
		}
		*target = num;
		*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	}
	if ((*str)[0] == '*' || ft_isdigit((*str)[0]))
		ft_pf_store_num_width(str, target, args, features);
	return (1);
}

int		ft_pf_store_precision(char **str, t_print *features, va_list args)
{
	int i;
	int pr;

	i = 0;
	pr = 0;
	if (!((*str)[0]))
		return (1);
	while ((*str)[i] == '.')
		i++;
	if (i)
	{
		features->is_precision = 1;
		*str = ft_memmove(*str, *str + i, ft_strlen(*str) - i + 1);
		if (!ft_isdigit((*str)[0]) && (*str)[0] != '*')
			features->precision = 0;
		else if ((*str)[0] == '*')
		  {
		  	pr = va_arg(args, int);
			if (pr < 0)
			  features->is_precision = 0;
			features->precision = pr < 0 ? 0 : pr;
			*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
		  }
		else
			ft_pf_store_num_width(str, &(features->precision), args, features);
	}
	else
		return (1);
	ft_pf_store_precision(str, features, args);
	return (1);
}

int		ft_pf_store_modifiers(char **str, t_print *features)
{
	const char	*mod_chars = "hljz";
	char		*modifiers;
	int			i;

	i = 0;
	modifiers = NULL;
	if (!((*str)[0]))
		return (1);
	while ((*str)[i] && ft_strchr(mod_chars, (*str)[i]))
		i++;
	if (!i)
		return (1);
	if (!(modifiers = ft_strdiv(str, modifiers, i)))
		return (0);
	i = 0;
	if (ft_strchr(modifiers, 'l'))
		features->mod = 'l';
	else if (modifiers[i] == 'h' && modifiers[i + 1] && modifiers[i + 1] == 'h')
		features->mod = 'H';
	else if (modifiers[i] == 'l' && modifiers[i + 1] && modifiers[i + 1] == 'l')
		features->mod = 'L';
	else
		features->mod = modifiers[0];
	free(modifiers);
	return (1);
}
