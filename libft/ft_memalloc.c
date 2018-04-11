/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:00:35 by rmaury            #+#    #+#             */
/*   Updated: 2018/04/11 15:50:03 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*str;

	mem = (void *)malloc(size);
	str = (char*)mem;
	if (mem != NULL)
	{
		while (size--)
			*str++ = 0;
	}
	return (mem);
}
