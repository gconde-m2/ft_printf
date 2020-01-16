/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:34:02 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:34:04 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr;

	ptr = dst;
	if ((dst == NULL && src == NULL) || !n)
		return (dst);
	while (n > 0)
	{
		*ptr = *((char *)src);
		n--;
		ptr++;
		src++;
	}
	return (dst);
}
