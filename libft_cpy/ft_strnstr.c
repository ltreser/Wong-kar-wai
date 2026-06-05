/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:20:52 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/24 02:21:22 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*locate a substring in a string*/
#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	while ((*big != '\0') && (len-- >= little_len))
	{
		if (ft_strncmp((char *)big, (char *)little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
    char *ptr;

  	ptr = ft_strnstr(largestring, smallstring, 4);
    printf("%p", ptr);
	return (0);
}*/
