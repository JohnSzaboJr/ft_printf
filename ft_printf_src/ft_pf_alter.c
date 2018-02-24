/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_alter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:52:47 by jszabo            #+#    #+#             */
/*   Updated: 2018/02/24 16:11:33 by jszabo           ###   ########.fr       */
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
