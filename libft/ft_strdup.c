/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:48:47 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/10 13:13:09 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ref;
	size_t	t_size;

	t_size = ft_strlen(s1) + 1;
	ref = (char *)malloc(t_size);
	if (!ref)
		return (NULL);
	ft_memcpy(ref, s1, t_size);
	return (ref);
}
