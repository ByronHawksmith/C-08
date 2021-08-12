#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dup)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*str;
	int				i;

	str = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (av[i] != 0 && i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].size = 0;
	str[i].str = 0;
	str[i].copy = 0;
	return (str);
}

/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	t_stock_str *strs;
	strs = ft_strs_to_tab(argc, argv);

	while (argc > 0)
	{
		printf("%s, ", strs->str);
		printf("%s, ", strs->copy);
		printf("%d\n", strs->size);
		strs++;
		argc--;
	}
}
*/
