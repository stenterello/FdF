#include "include/fdf.h"

void	die(char *str)
{
	ft_putendl_fd(str, 1);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		die("Usage: ./fdf [map_to_be_read]");
	init_map(argv[1], &map);
}



/*
char	*ft_strjoin_plus_plus(char *s1, char s2)
{
	int		i;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ret = ft_calloc(sizeof(char), (ft_strlen(s1) + 2));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	ret[i++] = s2;
	ret[i] = '\0';
	free(s1);
	return (ret);
}


int	get_num(char *line, int ind)
{
	int		ret;
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str = "";
	if (ind != (int)ft_strlen(str) && ft_isdigit(line[ind + 1]))
	{
		while (ft_isdigit(line[ind]) || line[ind] == 45)
			str = ft_strjoin_plus_plus(str, line[ind]);
		ret = ft_atoi(str);
		free(str);
		return (ret);
	}
	else
		return (line[ind] - 48);
}
*/
