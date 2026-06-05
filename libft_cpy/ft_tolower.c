/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:25:20 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/25 22:21:00 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convert uppercase letters to lowercase*/
//#include "libft.h"
//include <ctype.c>

int	ft_tolower(int c)
{
	if (c < 65 || c > 90)
		return (c);
	return (c + 32);
}
