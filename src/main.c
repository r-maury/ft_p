/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:37:58 by rmaury            #+#    #+#             */
/*   Updated: 2018/01/18 14:11:12 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DEBUG INCLUDES >> to delete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// END DEBUG INCLUDES >> to delete

#include "server.h"

int main(int argc, char const **argv)
{
	printf("%s\n", argv[1]);
	printf("%i\n", atoi(argv[0]));
	atoi(argv[1]);
	
	if (argc != 2 || *argv[1])
	{

	}
	return (0);
}