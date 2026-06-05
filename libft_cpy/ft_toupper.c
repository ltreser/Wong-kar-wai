/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:57:28 by ltreser           #+#    #+#             */
/*   Updated: 2023/05/20 21:59:30 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*convert lowercase letters to uppercase*/
//#include "libft.h"
//include <ctype.c>

int	ft_toupper(int c)
{
	if (c < 97 || c > 122)
		return (c);
	return (c - 32);
}
