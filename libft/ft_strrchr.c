/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:28:27 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:28:29 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		check;

	check = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			ptr = (char*)s;
			check++;
		}
		s++;
	}
	if (*s == c)
	{
		ptr = (char*)s;
		check++;
	}
	if (check > 0)
		return (ptr);
	else
		return (NULL);
}
