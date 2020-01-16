/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:31:59 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:32:00 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;
	size_t result;

	result = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	dst = dst + d;
	if (d <= dstsize)
		result = s + d;
	else
		return (dstsize + s);
	while (d + 1 < dstsize && *src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
		d++;
	}
	*dst = '\0';
	return (result);
}
