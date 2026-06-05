/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:56:26 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/07 18:04:16 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*append null-terminated string src to end of dest*/

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	total_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	if (src_len < size - dest_len)
	{
		ft_memcpy(dest + dest_len, src, src_len + 1);
	}
	else
	{
		ft_memcpy(dest + dest_len, src, size - dest_len - 1);
		dest[size - 1] = '\0';
	}
	return (total_len);
}
