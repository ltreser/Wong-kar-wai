/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 22:53:21 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/22 18:47:46 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* create new string from joint s1 & s2 */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jointstring;
	size_t	i;

	i = 0;
	jointstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!jointstring)
		return (0);
	ft_strlcpy(jointstring, s1, (ft_strlen(s1) + 1));
	ft_strlcat(jointstring, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (jointstring);
}
