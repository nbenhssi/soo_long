/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:03:16 by nbenhssi          #+#    #+#             */
/*   Updated: 2025/03/04 15:02:39 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *filename)
{
    char *line;
    char *all_lines;
    char *temp;
    int fd;
    char **map;

    all_lines = strdup("");
    if (!all_lines)
        return NULL;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (free(all_lines), NULL);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL || line[0] == '\n')
        {
            free(line);
            break;
        }
        temp = all_lines;
        all_lines = ft_strjoin(all_lines, line);
        free(temp);
        free(line);
        if (!all_lines)
            return (close(fd), NULL);
    }
    close(fd);
    if (all_lines[0] == '\0')
        return ( free(all_lines), NULL);
    map = ft_split(all_lines, '\n');
    return (free(all_lines), map);
}
