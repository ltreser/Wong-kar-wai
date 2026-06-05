/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:41:21 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/26 23:13:11 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
/*copy up to (size - 1) characters from src -> dest, null-terminate result*/
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_length;
	unsigned int	dest_index;

	src_length = 0;
	dest_index = 0;
	while (src[src_length] != '\0')
		src_length++;
	if (!size)
		return (src_length);
	while (src[dest_index] != '\0' && dest_index < (size - 1))
	{
		dest[dest_index] = src[dest_index];
		dest_index++;
	}
	dest[dest_index] = '\0';
	return (src_length);
}
