/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:34:19 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/07 18:05:55 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*return pointer to the last occurence of the character c in the string s*/
#include "libft.h"
//#include <stddef.h>
//#include <string.h>
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)s + i);
	if (!i)
		return (NULL);
	while (s[i] != (unsigned char)c)
	{
		i--;
		if (i == 0 && s[i] != (unsigned char) c)
			return (NULL);
	}
	return ((char *)s + i);
}
/*
int	main(void)
{
	char *src = "";
 	char *d1 = strrchr(src, 0);
 	char *d2 = ft_strrchr(src, 0);
	printf("original: %s\n", d1);
	printf("my ft: %s\n", d2);
}*/
