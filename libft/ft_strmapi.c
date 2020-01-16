/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:28:48 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:28:50 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s && f)
	{
		while (i < len)
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
