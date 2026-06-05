/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:47:23 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/26 00:24:36 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*memcpy copies n bytes from src to dest, memory areas must not overlap*/
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
