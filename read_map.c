#include "include/fdf.h"

void	one_by_one(char *line)
{
	int	i;
	int	i2;
	int	len;
	int	prev_len;

	i = 0;
	i2 = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			len = i - (len * i2);
			prev_len = len;
			if (len != prev_len)
				die("Text format error");
			i2++;
		}
		i++;
	}
}

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

int get_num(char *line, int ind)
{
    int     ret;
    int     i;
    char    *str;

    i = 0;
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

void    fill_matrix(char *line, t_map *map)
{
    int i;
    int i2;
    int num;

    (void)map;
    i = 0;
    i2 = 0;
    while (line[i] != '\0')
    {
        if (ft_isdigit(line[i]) || line[i] == 45)
            num = get_num(line, i);
        i++;
    }
}

void	check_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) && line[i] != 32 && line[i] != 43 && line[i] != 45 && line[i] != '\n')
			die("Text format error");
		i++;
	}
}

void	checks(char *file_name, t_map *map)
{
	int		fd;
	int		bytes;
	char	*line;
	char	*buff;

	fd = open(file_name, O_RDONLY);
	bytes = 1;
	buff = ft_calloc(2, sizeof(char));
	line = ft_calloc(2, sizeof(char));
	buff[1] = '\0';
	while (bytes > 0)
	{
		bytes = read(fd, buff, 1);
		line = ft_strjoin_plus(line, buff);
	}
	one_by_one(line);
	check_characters(line);
    fill_matrix(line, map);
	free(buff);
	free(line);
	close(fd);
}

void    init_map(char *file_name, t_map *map)
{
	(void)map;
    checks(file_name, map);
	//create_map();
}