/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:28:21 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:28:23 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_clean_in(const char *s1, const char *set)
{
	while (*set)
	{
		if (*s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*aux_fi;
	char	*ptr;

	if (!s1)
		return (NULL);
	aux_fi = (char *)s1 + (ft_strlen(s1) - 1);
	while ((ft_clean_in(s1, set)) && (s1))
		s1++;
	while ((ft_clean_in(aux_fi, set)) && (aux_fi > s1))
		aux_fi--;
	if (!(ptr = malloc(sizeof(char) * (aux_fi - s1) + 2)))
		return (NULL);
	ft_strlcpy(ptr, s1, (aux_fi - s1) + 2);
	return (ptr);
}
