/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:00:56 by ltreser           #+#    #+#             */
/*   Updated: 2023/06/25 23:54:51 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*check for alphanumerical characters*/
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
