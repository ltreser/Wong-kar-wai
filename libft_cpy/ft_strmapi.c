/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:07:01 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/13 17:21:56 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*apply function f to each character of string s, creating a new string*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strmapi;

	i = 0;
	if (!s)
		return (0);
	strmapi = malloc((ft_strlen(s)) + 1);
	if (!strmapi)
		return (NULL);
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
