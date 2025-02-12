/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:36:06 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/10 12:36:58 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_start_index(const char *s1, const char *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static int	get_end_index(const char *s1, const char *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*trimed;
	int				len;
	int				start;
	int				end;
	size_t			ref;

	if (!s1 || !set)
		return (NULL);
	start = get_start_index(s1, set);
	end = get_end_index(s1, set);
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	trimed = (unsigned char *)malloc(len + 1);
	if (!trimed)
		return (NULL);
	ref = 0;
	while (start <= end)
	{
		trimed[ref++] = s1[start++];
	}
	trimed[ref] = '\0';
	return ((char *)trimed);
}
