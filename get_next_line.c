#include "get_next_line.h"
#include <string.h>
#include <stdio.h>

int				join_parts(char **dst, const char *src)
{
	char		*new;

	new = ft_strjoin(*dst, src);
	if (new != NULL)
	{
		ft_strdel(dst);
		*dst = new;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			size;
	char		*buff;
	static char	*tmp_storage;
	char		*tmp;

	buff = ft_strnew(BUFF_SIZE);
	size = 1;
	tmp_storage = ft_strnew(BUFF_SIZE);
	tmp = tmp_storage;
	while (size > 0 && ft_strchr(tmp, '\n') == NULL)
	{
		ft_putendl(tmp);
		size = read(fd, buff, BUFF_SIZE);
		buff[size] = '\0';
		if (join_parts(&tmp, buff))
			{;}
		ft_strclr(buff);
		ft_putendl(tmp);
		ft_putendl("+++++++++");
	}
	ft_strdel(&buff);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_strsub(tmp, 0, ft_indexof(tmp, '\n'));
		tmp_storage = ft_strsub(tmp, ft_indexof(tmp, '\n'), (ft_strlen(tmp) - ft_strlen(*line)));
		//printf("==========\n%i\n%s\n==========\n", (int)(ft_strlen(tmp_storage) - ft_strlen(*line)), tmp_storage);
		ft_strdel(&tmp);
	}
	else if (size <= 0)
	{
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (0);
	}
	else if (size < 1)
	{
		if (tmp != NULL)
		{
			*line  =  ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		return (-1);
	}
	return (1);
}
