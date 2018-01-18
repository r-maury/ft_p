/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:37:58 by rmaury            #+#    #+#             */
/*   Updated: 2018/01/18 15:03:22 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DEBUG INCLUDES >> to delete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// END DEBUG INCLUDES >> to delete

#include "server.h"

int main(int argc, char const **argv)
{
	printf("%i\n", argc);
	atoi(argv[1]);
	int sock_fd;
		ft_putendl("ERROR = ");
		ft_strcat("ERROR = ", "caca");

	sock_fd = socket(PF_INET, SOCK_STREAM, 0);

	if (sock_fd == -1)
		ft_putendl(ft_strcat("ERROR = ", ft_itoa(errno)));
	else
	{
		ft_putendl(ft_strcat("Socket created in fd:", ft_itoa(sock_fd)));
	}
	return (0);
}