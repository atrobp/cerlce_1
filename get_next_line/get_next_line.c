/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atopalli <atopalli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:25:34 by atopalli          #+#    #+#             */
/*   Updated: 2022/06/20 18:36:51 by atopalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	int			ret;

	if ((str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		if (fd != -1)
		{
			while ((ret = read(fd, str, BUFFER_SIZE)))
			{
				str[ret] = '\0';
				return (str);
			}
			free(str);
		}
	}
	return (NULL);
}
