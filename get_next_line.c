#include "get_next_line.h"
#include <stdio.h>

static char		*process(char *buff, char ***tmp, int *cnt)
{
//	char		**tmp1;
	static char	*tmp2 = NULL;
	char		*tmp3;
	char		*line;

//	tmp1 = *tmp;
	tmp3 = NULL;
	line = NULL;
	if (tmp2 == NULL)
		tmp2 = ft_strdup((const char *)buff);
	else
	{
		tmp3 = tmp2;
		tmp2 = ft_strjoin((char const *)tmp3, (char const *)buff);
		ft_strdel(&tmp3);
	}
	ft_putendl(buff);
	if (ft_strchr((const char *)buff, '\n') != NULL)
	{
		tmp3 = ft_strtrim(tmp2);
		*tmp = ft_strsplit((char const *)tmp3, '\n');
		line = ft_strdup(*tmp[*cnt]);
		*cnt += 1;
		ft_strdel(&tmp2);
		ft_strdel(&tmp3);
		return (line);
	}
	return (NULL);
}

static int		get_new_line(char **line, int fd, char ***tmp, int *cnt)
{
	int			size;
	char		*buff;
	
	buff = ft_strnew(BUFF_SIZE);
	size = 0;
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		if ((*line = process(buff, tmp, cnt)) != NULL)
			return (1);
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	return (size);
}

int				get_next_line(const int fd, char **line)
{
	static char	**tmp = NULL;
	static int	c = 0;
	int			status;

	status = 0;
	if (*line != NULL)
		ft_strdel(line);
	if (tmp != NULL)
	{
		ft_putendl("ok");
		printf("%i\n", c);
		if (tmp[c] != NULL)
		{
		ft_putendl("ok2");
			*line = ft_strdup((const char *)tmp[c]);
			ft_strdel(&tmp[c++]);
		}
	}
	else
	{
		if (tmp != NULL)
		{
			ft_putendl("j1");
			ft_arrdel(&tmp);
		}
		else
			ft_putendl("j1.1");
		c = 0;
		status = get_new_line(line, fd, &tmp, &c);
		if (status == 0 && tmp != NULL)
		{
			ft_putendl("j2");
			//ft_arrdel(&tmp)
		}
		else
			ft_putendl("j3");
		return (status);
	}
	return (1);
}
