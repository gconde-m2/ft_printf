/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:28:09 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:28:15 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_create(char const **s, unsigned int *start,
		size_t *len, char **ptr)
{
	size_t cont;

	cont = ft_strlen(*s);
	*s = *s + *start;
	cont = (cont - *start) + 1;
	if (cont <= *len)
	{
		if (!(*ptr = malloc(cont + 1)))
			return (NULL);
		ft_strlcpy(*ptr, *s, cont + 1);
	}
	else
	{
		if (!(*ptr = malloc(*len + 1)))
			return (NULL);
		ft_strlcpy(*ptr, *s, *len + 1);
	}
	return (*ptr);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	cont;
	char	*ptr;

	if (!s)
		return (NULL);
	cont = ft_strlen(s);
	if (cont > start)
	{
		ptr = ft_create(&s, &start, &len, &ptr);
	}
	else
	{
		if (!(ptr = malloc(1)))
			return (NULL);
		*ptr = '\0';
	}
	return (ptr);
}
