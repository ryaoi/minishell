
#include "minishell.h"

char		*straddonefree(char *str, char c, int i)
{
	char	*stock;
	char	*result;

	stock = ft_strnew(1);
	stock[0] = c;
	result = ft_strjoini(str, stock, i);
	ft_strdel(&stock);
	return (result);
}
