/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:47:27 by nbenhssi          #+#    #+#             */
/*   Updated: 2024/12/29 01:31:21 by nbenhssi         ###   ########.fr       */
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
		res = malloc(i + 2);
		if (!res)
			return (NULL);
		ft_strncpy(res, str, i + 1);
		res[i + 1] = '\0';
		return (res);
	}
	return (NULL);
}




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

static char	*check_buffer(char **str)
{
	char	*line;

	line = strfchr(*str);
	if (line)
	{
		chyata(str);
		return (line);
	}
	return (NULL);
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

// char	*get_next_line(int fd)
// {
// 	static char		*str;
// 	char			*buffer;
// 	ssize_t			bytes_read;
// 	char			*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		line = check_buffer(&str);
// 		if (line)
// 			return (line);
// 		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
// 		if (!(buffer))
// 			return (NULL);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (free(buffer), free(str), str = NULL, NULL);
// 		if (bytes_read == 0)
// 		{
// 			free(buffer);
// 			if (!str || !*str)
// 				return (free(str), str = NULL, NULL);
// 			break ;
// 		}
// 		str = ft_strcat(str, buffer);
// 	}
// 	return (get_line_from_str(&str));
// }




// char	*get_next_line(int fd)
// {
// 	static char		*str;
// 	char			*buffer;
// 	ssize_t			bytes_read;
// 	char			*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		line = check_buffer(&str);
// 		if (line)
// 			return (line);
// 		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
// 		if (!(buffer))
// 			return (NULL);
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (free(buffer), free(str), str = NULL, NULL);
// 		if (bytes_read == 0)
// 		{
// 			free(buffer);
// 			if (!str || !*str)
// 				return (free(str), str = NULL, NULL);
// 			break ;
// 		}
// 		str = ft_strcat(str, buffer);
// 	}
// 	return (get_line_from_str(&str));
// }

// last 
// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*buffer;
// 	char		*line;
// 	ssize_t		bytes_read;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (!(line = strfchr(str)))
// 	{
// 		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
// 		if (!buffer || (bytes_read = read(fd, buffer, BUFFER_SIZE)) < 0)
// 			return (free(buffer), free(str), str = NULL, NULL);
// 		if (!bytes_read)
// 		{
// 			free(buffer);
// 			if (!str || !*str)
// 				return (free(str), str = NULL, NULL);
// 			line = str;
// 			return (str = NULL, line);
// 		}
// 		str = ft_strcat(str, buffer);
// 	}
// 	chyata(&str);
// 	return (line);
// }



char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = strfchr(str);
	while (!line)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
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
