/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:16 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/27 03:12:15 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dimension_map(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd),i);
}

char	**read_map(char *filename)
{
	char	*line;
	int		i;
	int		size;
	int		fd;
	char	**map;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (NULL);
	size = dimension_map(fd);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (free(map),NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(map), NULL);
	while (line)
	{
		if (line[0] != '\n')
			map[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (close(fd), map);
}
