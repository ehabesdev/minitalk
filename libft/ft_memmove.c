/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehabes <ehabes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:32:16 by ehabes            #+#    #+#             */
/*   Updated: 2024/11/04 13:29:26 by ehabes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*_src;
	unsigned char	*_dest;

	_src = (unsigned char *)src;
	_dest = (unsigned char *)dest;
	if (_src == _dest)
		return (_dest);
	if (_src < _dest && _dest < _src + len)
	{
		_src += len;
		_dest += len;
		while (len--)
			*--_dest = *--_src;
	}
	else
	{
		while (len--)
			*_dest++ = *_src++;
	}
	return (dest);
}
