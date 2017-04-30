/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:59:08 by mdlamini          #+#    #+#             */
/*   Updated: 2016/07/16 07:12:04 by mdlamini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		main(int c, char **v)
{
	char 	*line;
	int		fd;

	line = NULL;
	fd = 0;
	if (c > 1)
	{
		fd = open(v[1], O_RDONLY);
		//int n = -1;
		while (get_next_line((const int)fd, &line) > 0)
		{
			//ft_putendl(line);
			//ft_strdel(&line);
			//n++;
			//if (n == 3)
			//	break;
		}
//		get_next_line((const int)fd, &line);
//		ft_putendl(line);
	}
	return (0);
}
