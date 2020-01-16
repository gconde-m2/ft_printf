/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:28:33 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:28:35 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr;
	size_t		check;

	if (*needle == '\0')
		return ((char*)haystack);
	while (len > 0 && *haystack != '\0')
	{
		check = 0;
		if (*haystack == *needle)
		{
			ptr = (char*)haystack;
			while (check < len && *(ptr + check) == *(needle + check))
			{
				if (*(needle + check + 1) == '\0')
					return (ptr);
				check++;
			}
		}
		len--;
		haystack++;
	}
	return (NULL);
}
