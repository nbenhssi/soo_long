/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhssi <nbenhssi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:47:39 by nbenhssi          #+#    #+#             */
/*   Updated: 2024/12/29 00:19:13 by nbenhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int			len_dest;
	int			len_src;
	char		*new_str;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	new_str = malloc(len_dest + len_src + 1);
	if (!new_str)
		return (NULL);
	if (dest)
		ft_strcpy(new_str, dest);
	else
		new_str[0] = '\0';
	ft_strcpy(new_str + len_dest, src);
	new_str[len_dest + len_src] = '\0';
	free(dest);
	free(src);
	return (new_str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return (s);
}