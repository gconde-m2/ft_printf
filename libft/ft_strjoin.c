/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:32:06 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:32:08 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	cont = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = malloc(cont + 1)))
		return (NULL);
	ft_strlcpy(ptr, s1, cont + 1);
	ft_strlcat(ptr, s2, cont + 1);
	return (ptr);
}
