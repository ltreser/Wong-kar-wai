/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:14:14 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/13 17:20:11 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*print character to file descriptor, fd = 1 for terminal*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
