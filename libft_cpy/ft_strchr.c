/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:38:11 by ltreser           #+#    #+#             */
/*   Updated: 2023/05/20 20:38:38 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*return a pointer to the first ocurrence of c in s*/
//#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}
