/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:37:48 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/13 17:10:32 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
/*splits string into substrings devided by delimiter c, returns 2d array*/

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

void	*ft_mallocprotect(char **stringarray, int j)
{
	if (!stringarray[j])
	{
		while (j--)
			free(stringarray[j]);
		free(stringarray);
	}
	return (stringarray);
}

char	**ft_split(char const *s, char c)
{
	char	**stringarray;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = 0;
	len = 0;
	stringarray = (char **)ft_calloc(((count_words(s, c)) + 1), sizeof(char *));
	while ((++i < (int)ft_strlen(s)) && s[i] && stringarray)
	{
		if ((!(s[i] == c && i == 0)) && s[i] != c && s[i + 1] && ++len)
			;
		else if ((s[i] == c && len && stringarray) 
			|| (((!s[i + 1]) && s[i] != c) && (len++, i++)))
		{
			stringarray[j++] = ft_substr(s, i - len, len);
			stringarray = ft_mallocprotect(stringarray, (j - 1));
			len = 0;
		}
	}
	return (stringarray);
}
/*
#include <stdio.h>
#include <unistd.h>
int main(void)
{
    char **str;

    str = ft_split("nonempty", 0);
    for (int i = 0; str[i]; i++)
    {
        printf("%s\n", str[i]);
    }
	printf("count words: %d\n", (count_words("nonempty", 0)));
}*/
