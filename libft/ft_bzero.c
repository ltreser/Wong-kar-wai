/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 00:44:55 by ltreser           #+#    #+#             */
/*   Updated: 2023/05/26 00:46:25 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*erases the initial n bytes started where s points at by writing 0*/

#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
