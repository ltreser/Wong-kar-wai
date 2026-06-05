/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 23:51:36 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/13 17:15:13 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
/*return copy of s1 with characters from set removed from top and back*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	ri;
	size_t	setlen;

	i = 0;
	ri = (ft_strlen(s1) - 1);
	setlen = ft_strlen(set);
	while (setlen--)
	{
		if (s1[i] == set[setlen])
		{
			i++;
			setlen = ft_strlen(set);
		}
	}
	setlen = ft_strlen(set);
	while (setlen--)
	{
		if (s1[ri] == set[setlen])
		{
			ri--;
			setlen = ft_strlen(set);
		}
	}
	return (ft_substr(s1, i, (ri - i + 1)));
}
