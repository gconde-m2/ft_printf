/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:26:19 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:26:20 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr;
	unsigned char x;

	x = c;
	ptr = dst;
	while (*((unsigned char *)src) != x && n > 0)
	{
		*ptr = *((unsigned char *)src);
		ptr++;
		src++;
		n--;
	}
	if (*((unsigned char *)src) == x && n > 0)
	{
		*ptr = x;
		ptr++;
		return (ptr);
	}
	return (NULL);
}
