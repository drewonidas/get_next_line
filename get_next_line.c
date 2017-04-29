#include "get_next_line.h"
#include <stdio.h>

int				join_parts(char **dst, const char *src)
{
	char		*new;

	new = ft_strjoin(*dst, src);
	if (new != null)
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
	size = 0;
	tmp_storage = ft_strnew(BUFF_SIZE);
	tmp = tmp_storage;
	while ((size = read(fd, buff, BUFF_SIZE)) > 0 && ft_strchr(tmp, '\n'))
	{
		buff[size] = '\0';
		join_parts(tmp, buff);
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	if (ft_strchr(tmp, '\n'))
	{
		*line = ft_strsub(tmp, 0, ft_indexof(tmp, '\n'));
		tmp_storage = ft_strsub(tmp, ft_indexof(tmp, '\n'), (ft_strlen(tmp) - ft_strlen(*line)));
		ft_strdel(&tmp);
	}
	else if (size == 0)
	{
		*line = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (0);
	}
	return (1);
}
