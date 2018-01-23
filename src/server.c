/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:37:58 by rmaury            #+#    #+#             */
/*   Updated: 2018/01/23 19:53:12 by rmaury           ###   ########.fr       */
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
	int sock_fd;
	struct sockaddr_in server_addr;
	if (argc != 2) 
	{
		ft_putendl_fd(ft_strjoin("Usage: ", ft_strjoin(argv[0], " port")), 2);
		return(0);
	}
	sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	bind(sock,(struct sockaddr*) &server_address, sizeof(server_address));
	listen(sock_fd, 5)

	// if (sock_fd == -1)
	// {
	// 	ft_putstr("Error:");
	// 	ft_putendl(ft_itoa(errno));
	// }
	// else
	// {
	// 	ft_putstr("Socket created in fd:");
	// 	ft_putendl(ft_itoa(sock_fd));
	// }
	return(0);
}