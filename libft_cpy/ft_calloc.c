/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:13:40 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/07 22:35:35 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*allocate memory for array of nmemb elements of size bytes each set to 0*/
#include <stdlib.h>
#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb * size > SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	while (nmemb--)
		ft_bzero((ptr + (nmemb * size)), size);
	return (ptr);
}
