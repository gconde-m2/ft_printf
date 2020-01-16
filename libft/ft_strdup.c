/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:32:13 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:32:15 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	cont;
	char	*ptr;

	cont = ft_strlen(s1);
	if (!(ptr = malloc(cont + 1)))
		return (NULL);
	ft_strlcpy(ptr, s1, cont + 1);
	return (ptr);
}
