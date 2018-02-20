/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:49:38 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 15:53:08 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int     ft_pf_handle_signed_char(va_list args, t_print *features, int *ret)
{
  signed char c;
    char    *str;
    char    *new;
    char    *spaces;

    c = (signed char)(va_arg(args, int));
    str = ft_itoa(c);
    
    //    str = ft_strnew(1);
    //    str[0] = c;
        if (!(new = ft_strdup(str)) ||
    	!ft_pf_precision_s(&new, features) ||
    	!ft_pf_width_fl_zeros_left(&new, &spaces, features))
          return (0);
    ft_putstr(new);
    *ret = *ret + ft_strlen(new);
    free(new);
    return (1);  
}
