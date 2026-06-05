/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:44:43 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/08 01:31:01 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*allocates with malloc and returns integer as string, neg numbers handled*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_numlen(int i)
{
	int	numlen;

	numlen = 0;
	if (i == 0)
		numlen++;
	if (i < 0)
		numlen++;
	while (i)
	{
		i = i / 10;
		numlen++;
	}
	return (numlen);
}

char	*ft_itoa(int n)
{
	char	*string;
	char	*numbers;
	int		i;

	numbers = "0123456789";
	i = ft_numlen(n);
	string = malloc(i + 1);
	if (!string)
		return (0);
	string[i] = '\0';
	if (n == 0)
		string[0] = 48;
	if (n < 0)
		string[0] = '-';
	while ((n > 0 && i--) || (n < 0 && --i))
	{
		if (n < 0)
			string[i] = numbers[(n % 10) * -1];
		if (n > 0)
			string[i] = numbers[n % 10];
		n = n / 10;
	}
	return (string);
}
/*
int main(void)
{
	int num = 0;
    char *str = ft_itoa(num);
    printf("Number: %d\nString: %s\n", num, str);
    free(str); // Remember to free the allocated memory
    return (0);
}
*/
