/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_struct_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:26:51 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 10:28:00 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int  ft_pf_struct_init(t_print *features)
{
    features->fl_left_just = 0;
    features->fl_signed_num = 0;
    features->fl_sign_space = 0;
    features->fl_prep_zeros= 0;
    features->fl_alter = 0;
    features->width = 0;
    features->precision = 0;
    features->mod_hh = 0;
    features->mod_ll = 0;
    features->mod_h = 0;
    features->mod_l = 0;
    features->mod_j = 0;
    features->mod_z = 0;
    features->type = '\0';
    return (1);
}
