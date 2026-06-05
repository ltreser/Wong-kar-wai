/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:06:08 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/07 19:18:02 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*scan inicial n bytes pointed to by s for the first instance of c*/
#include <stddef.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *) s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (0);
}
/*
int	main(void)
{
	char *c = "hellobarra";
	printf("or: %s\n", (char*)(ft_memchr((const void*)c, 'r', 100)));
	return (0);
}*/
