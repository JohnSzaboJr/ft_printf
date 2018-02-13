/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:53:24 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/12 17:04:02 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

void ft_pf_store_flags(char **str, t_print *features)
{
    const char  *flags = "-+ 0#";
    int         i;

    i = 1;
    while (ft_strchr(flags, (*str)[i]))
    {
        if ((*str)[i] == '0')
            features->fl_prep_zeros = 1;
        if ((*str)[i] == ' ')
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
}

void ft_pf_store_num_width(char **str, int *target, va_list args)
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
}

void ft_pf_store_precision(char **str, int *target, va_list args)
{
    if ((*str)[0] == '.')
    {
        *str = ft_memmove(*str, *str + 1, ft_strlen(*str));
        ft_pf_store_num_width(str, target, args);
    }
}

int  ft_pf_store_modifiers(char **str, t_print *features)
{
    const char  *modifiers = "hljz";
    int         i;

    i = 0;
    while (ft_strchr(modifiers, (*str)[i]))
        i++;
    if (i > 0 && !(features->modifiers = ft_strdiv(str, features->modifiers, i)))
        return (0);
    return (1);
}
