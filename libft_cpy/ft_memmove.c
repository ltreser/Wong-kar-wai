/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:42:17 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/26 00:22:47 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copy n bytes from memory area src to dest, memory areas may overlap*/
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	int						i;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
