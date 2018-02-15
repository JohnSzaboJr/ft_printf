/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:53:24 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/14 17:12:48 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int		ft_pf_store_type(char **str, char *type)
{
	const char *types = "%sSpdDioOuUxXcC";

	if (!ft_strchr(types, (*str)[0]))
		return (0);
	*type = (*str)[0];
	*str = ft_memmove(*str, *str + 1, ft_strlen(*str));
	return (1);
}

int		ft_pf_store_flags(char **str, t_print *features)
{
    const char  *flags = "-+ 0#";
    int         i;

    i = 0;
    while (ft_strchr(flags, (*str)[i]))
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

int		ft_pf_store_num_width(char **str, size_t *target, va_list args)
{
    if (ft_isdigit((*str)[0]))
    {
        *target = ft_atoi(*str);
        *str = ft_memmove(*str, *str + ft_numlen(*target),
                          ft_strlen(*str) - ft_numlen(*target) + 1);
    }
    else if ((*str)[0] == '*')
    {
        *target = va_arg(args, int);
        *str = ft_memmove(*str, *str + 1, ft_strlen(*str));
    }
	return (1);
}

int		ft_pf_store_precision(char **str, size_t *target, va_list args)
{
    if ((*str)[0] == '.')
    {
        *str = ft_memmove(*str, *str + 1, ft_strlen(*str));
        ft_pf_store_num_width(str, target, args);
    }
	return (1);
}

int		ft_pf_store_modifiers(char **str, t_print *features)
{
    const char  *mod_chars = "hljz";
	char		*modifiers;
    int         i;

    i = 0;
	modifiers = NULL;
    while (ft_strchr(mod_chars, (*str)[i]))
        i++;
	if (!i)
		return (1);
    if (!(modifiers = ft_strdiv(str, modifiers, i)))
        return (0);
	if (ft_strstr(modifiers, "hh"))
		features->mod_hh = 1;
	if (ft_strstr(modifiers, "ll"))
		features->mod_ll = 1;
	if (!(features->mod_hh) && ft_strchr(modifiers, 'h'))
		features->mod_h = 1;
	if (!(features->mod_ll) && ft_strchr(modifiers, 'l'))
		features->mod_l = 1;
	if (ft_strchr(modifiers, 'j'))
		features->mod_j = 1;
	if (ft_strchr(modifiers, 'z'))
		features->mod_z = 1;
	free(modifiers);
    return (1);
}
