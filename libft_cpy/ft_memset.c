/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:37:02 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/25 23:51:23 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*fill the first n bytes of the memory area pointed to by s with c*/
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n--)
	{
		*ptr = (unsigned char) c;
		ptr++;
	}
	return (s);
}
