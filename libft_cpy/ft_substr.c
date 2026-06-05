/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:54:58 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/25 23:45:49 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* create a substring from s that starts at start and has the length len */
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	len_s_from_start;

	i = 0;
	if (!s)
		return (0);
	if (start >= (ft_strlen(s)))
		return (ft_strdup(""));
	len_s_from_start = ft_strlen(s + start);
	if (len_s_from_start < len)
		len = len_s_from_start;
	substring = malloc(len + 1);
	if (!substring)
		return (0);
	while (len--)
	{
		substring[i] = s[start++];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
