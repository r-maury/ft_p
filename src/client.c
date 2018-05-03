/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 15:30:51 by rmaury            #+#    #+#             */
/*   Updated: 2018/05/03 18:31:06 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// DEBUG INCLUDES >> to delete
#include <errno.h>
// END DEBUG INCLUDES >> to delete
#include "client.h"

int		g_prompt = 0;

void	quit_server(int sockfd)
{
	ft_putendl("Quitting Ft_p, goodbye...");
	close(sockfd);
	exit(0);
}

void	exec_command(char *input, int sockfd)
{
	if (ft_strcmp(input, "quit") == 0)
		quit_server(sockfd);
	else if (ft_strcmp(input, "pwd") == 0)
		send(sockfd, "pwd", 3, 0);
	else
		printf("Unknown Command \n");
}

int 	connection_setup(char* host, char* port)
{
	int 				sockfd;
	struct sockaddr_in 	server_addr;
	struct hostent 		*server_info;

	ft_memset(&server_addr, 0, sizeof(server_addr));

	if ((server_info = gethostbyname(host)) == NULL)
	{
		printf("gethostbyname error = %s\n", strerror(errno));	
		return (-1);
	}

	server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)server_info->h_addr)));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(ft_atoi(port));

	sockfd = socket(server_addr.sin_family, SOCK_STREAM, 0);

	if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
	{
		printf("CONNECTION TO %s:%i \033[31mERROR\033[0;m!\n", server_info->h_name, ntohs(server_addr.sin_port));
		quit_server(sockfd);
	}
	else
		printf("CONNECTION TO %s:%i \033[32mSUCCESS\033[0;m!\n", server_info->h_name, ntohs(server_addr.sin_port));	
	return (sockfd);
}

int main(int argc, char **argv) 
{
	char	*line;
	char	buf[50];
	int 	sockfd;

	if (argc != 3)
	{
		printf("Usage: %s <machine> <port>\n", argv[0]);
		return (1);
	}

	if ((sockfd = connection_setup(argv[1], argv[2])) == -1)
		return (1);

	while (42)
	{
		g_prompt == 1 ? g_prompt = 0 : ft_putstr(FT_PROMPT);
		if (get_next_line(0, &line) == 0)
			quit_server(sockfd);
		else
			exec_command(line, sockfd);
		read(sockfd, &buf, 50);
		printf("%s\n", buf);
	}
	return (0);
}
