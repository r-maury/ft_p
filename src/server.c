/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:37:58 by rmaury            #+#    #+#             */
/*   Updated: 2018/01/23 20:25:12 by rmaury           ###   ########.fr       */
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
	int reuse;
	struct sockaddr_in server_addr;

	reuse = 1;

	if (argc != 2) 
	{
		ft_putendl_fd(ft_strjoin("Usage: ", ft_strjoin(argv[0], " port")), 2);
		return(0);
	}

	sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	bind(sock_fd,(struct sockaddr*) &server_addr, sizeof(server_addr));
	listen(sock_fd, 5);

	while(42)
	{
		accept(sock_fd, *client_addr, client_len);
	}

	return(0);
}