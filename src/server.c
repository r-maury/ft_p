/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:37:58 by rmaury            #+#    #+#             */
/*   Updated: 2018/04/06 16:40:24 by rmaury           ###   ########.fr       */
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
	int 				sock_fd;
	int 				reuse;
	struct sockaddr_in 	server_addr;
	struct sockaddr_in 	client_addr;
	socklen_t 			client_size;

	reuse = 1;

	if (argc != 2) 
	{
		printf("Usage: %s <port>\n", argv[0]);
		// ft_putendl_fd(ft_strjoin("Usage: ", ft_strjoin(argv[0], " port")), 2);
		return (0);
	}

	ft_memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(ft_atoi(argv[1]));

	sock_fd = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
	bind(sock_fd,(struct sockaddr*) &server_addr, sizeof(server_addr));
	listen(sock_fd, 5);

	while(42)
	{
		client_size = sizeof(client_addr);
		accept(sock_fd, (struct sockaddr *) &client_addr, &client_size);
	}

	return (0);
}