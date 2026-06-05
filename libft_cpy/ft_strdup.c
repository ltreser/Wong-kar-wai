/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:10:42 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/25 23:50:25 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*return pointer to new duplicate of string s*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = ft_strlen(s);
	ptr = (char *) malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	while (--i >= 0)
		ptr[i] = s[i];
	return (ptr);
}
