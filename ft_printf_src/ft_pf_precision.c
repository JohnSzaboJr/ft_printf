/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 10:52:42 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/15 13:08:30 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_precision_s(char **str, size_t precision)
{
	if (ft_strlen(*str) > precision)
		(*str)[precision] = '\0';
	return (1);
}
