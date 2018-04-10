/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:30:51 by rmaury            #+#    #+#             */
/*   Updated: 2018/04/10 18:53:31 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// DEBUG INCLUDES >> to delete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
// END DEBUG INCLUDES >> to delete
#include "client.h"

int		g_prompt = 0;

void	exit_server(char *str, int sockfd)
{
	close(sockfd);
	if (ft_strcmp(str, "exit") == 0)
	{
		ft_putendl("exit");
		exit(0);
	}
}

void	empty_line(char *line)
{
	if (line[0] == 0)
	{
		ft_putstr(">> ");
		g_prompt = 1;
	}
	else
		g_prompt = 0;
}

int main(int argc, char const **argv) 
{
	int 				sockfd;
	int 				r;
	char				*line;
	struct sockaddr_in 	server_addr;
	struct hostent 		*server_info;

	if(argc != 3)
	{
		printf("Usage: %s <machine> <port>\n", argv[0]);
		return (1);
	}

	ft_memset(&server_addr, 0, sizeof(server_addr));

	if((server_info = gethostbyname(argv[1])) == NULL)
	{
		printf("gethostbyname error = %s\n", strerror(errno));	
		return (1);
	}

	printf("addr name = %s\n", server_info->h_name);
	printf("addr type = %i\n", server_info->h_addrtype);


	server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)server_info->h_addr)));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(ft_atoi(argv[2]));
	printf("addr = %u\nfamily = %i\nport = %i\n", server_addr.sin_addr.s_addr, server_addr.sin_family, ntohs(server_addr.sin_port));

	sockfd = socket(server_addr.sin_family, SOCK_STREAM, 0);

	printf("socket error = %s\n", strerror(errno));
	printf("socket = %i\n", sockfd);

	r = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	printf("connect error = %s\n", strerror(errno));
	printf("Connect = %i\n", r);

	while(42)
	{
		g_prompt == 1 ? g_prompt = 0 : ft_putstr(FT_PROMPT);
		if(get_next_line(0, &line) == 0)
			exit_server("exit", sockfd);
		if(ft_strcmp(line, "exit") == 0)
			exit_server("exit", sockfd);
	}
	return (0);
}
