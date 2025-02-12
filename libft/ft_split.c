/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:18:58 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/14 18:37:02 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count(const char *str, char spr)
{
	int	in_str;
	int	count;

	count = 0;
	in_str = 0;
	while (*str)
	{
		if (*str != spr && in_str == 0)
		{
			in_str = 1;
			count++;
		}
		else if (*str == spr)
			in_str = 0;
		str++;
	}
	return (count);
}

static char	*ft_memory_allocation(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, str, i);
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	**start_index;

	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!array)
		return (NULL);
	start_index = array;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			*array = ft_memory_allocation(s, c);
			if (!*array)
				return (ft_free(start_index));
			array++;
		}
		while (*s && *s != c)
			s++;
	}
	*array = NULL;
	return (start_index);
}
