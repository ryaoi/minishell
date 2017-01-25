
#include "minishell.h"

int			read_stdin(char **line)
{
	int		ret;
	char	buf[1];
	char	*str;
	int		flag;

	flag = 0;
	ret = 0;
	str = ft_strnew(0);
	while ((ret = read(0, buf, 1) > 0) && *buf != '\n')
	{
		flag = 1;
		buf[ret] = '\0';
		str = ft_strjoini(str, buf, 1);
	}
	*line = ft_strdup(str);
	ft_strdel(&str);
	if (*buf == '\n' && flag == 0)
		return (0);
	return (ret);
}
