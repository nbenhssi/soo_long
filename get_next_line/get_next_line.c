/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:47:27 by nbenhssi          #+#    #+#             */
/*   Updated: 2024/12/29 12:00:34 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strfchr(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		res = malloc(i + 1);
		if (!res)
			return (NULL);
		ft_strncpy(res, str, i);
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

static void	chyata(char **str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str || !*str)
		return ;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	temp = malloc(ft_strlen(*str + i) + 1);
	if (!temp)
		return ;
	ft_strcpy(temp, *str + i);
	free(*str);
	*str = temp;
}

static char	*get_line_from_str(char **str)
{
	char	*line;

	if (*str && **str)
	{
		line = *str;
		*str = NULL;
		return (line);
	}
	free(*str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		return (NULL);
	}
	line = strfchr(str);
	while (!line)
	{
		buffer = ft_calloc((size_t)(BUFFER_SIZE) + 1, 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(str), str = NULL, NULL);
		if (bytes_read == 0 && (!str || !*str))
			return (free(buffer), free(str), str = NULL, NULL);
		if (bytes_read == 0)
			return (free(buffer), get_line_from_str(&str));
		str = ft_strcat(str, buffer);
		line = strfchr(str);
	}
	chyata(&str);
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt", O_RDONLY);
//     char *line;

// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
//         free(line);
// 	}
//     // line = get_next_line(fd);
// 	// printf("%s", line);
//     // free(line);
//     close(fd);
// 	return 0;
// }