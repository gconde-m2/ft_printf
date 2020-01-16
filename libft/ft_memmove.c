/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:33:57 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:33:58 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *ptr_dst;
	char *ptr_src;

	ptr_dst = dst;
	ptr_src = (char*)src;
	if ((dst == NULL && src == NULL) || len <= 0)
		return (dst);
	if (src < dst)
	{
		ptr_dst = ptr_dst + (len - 1);
		ptr_src = ptr_src + (len - 1);
		while (len > 0)
		{
			*ptr_dst-- = *ptr_src--;
			len--;
		}
		return (dst);
	}
	while (len-- > 0)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
