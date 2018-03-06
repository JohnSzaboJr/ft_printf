/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_alter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:52:47 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/06 11:58:04 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../ft_printf.h"

int	ft_pf_alter(char **str, int alter)
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	if (!alter)
		return (1);
	while ((*str)[i])
	{
		if ((*str)[i] != ' ' && (*str)[i] != '0')
			break ;
		i++;
	}
	if (i == ft_strlen(*str))
		return (1);
	if (!i)
	{
		if (!(new = ft_strjoin("0", *str)))
			return (0);
		free(*str);
		*str = new;
	}
	if (i > 0)
		(*str)[i - 1] = '0';
	return (1);
}

int	ft_pf_alter_x(char **str, t_print *features)
{
	if ((*str)[0] == '0')
		features->fl_alter = 0;
	if (features->fl_alter && !ft_pf_hex_sign(str))
		return (0);
	return (1);
}

int     ft_pf_alter_x_final(char **str, t_print *features)
{
  if (features->fl_alter && !ft_pf_hex_sign_zeros(str))
    return (0);
  return (1);
}
