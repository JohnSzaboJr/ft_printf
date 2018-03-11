/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jszabo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:00:30 by jszabo            #+#    #+#             */
/*   Updated: 2018/03/11 14:42:11 by jszabo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_determine_len(int n, int len)
{
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		len++;
	}
	return (len + 1);
}

char			*ft_ftoa(double n, size_t pr)
{
    int		neg;
	int		len;
	char	*ans;
	long long		tmp;
	char		*beg;

	if (!(beg = ft_longlongtoa((long long)n)))
		return (NULL);
	if (!pr)
		return (beg);
	tmp = (long long)(n * ft_recursive_power(10, (int)pr));
	len = 0;
	neg = (tmp < 0) ? 1 : 0;
	tmp = (tmp < 0) ? -tmp : tmp;
	len = ft_determine_len(tmp, len);
	len = (tmp == 0 || neg) ? len + 1 : len;
	if (!(ans = (char *)malloc(sizeof(*ans) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	while (len > 0)
	{
		ans[len - 1] = (tmp % 10) + '0';
		tmp = (tmp - (tmp % 10)) / 10;
		len--;
	}
	ans[0] = (neg) ? '-' : '0';
	len = ft_strlen(ans);
	ans = ft_strcpy(ans, beg);
	ans[len - pr - 1] = '.';
	free(beg);
	return (ans);
}
