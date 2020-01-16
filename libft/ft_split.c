/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 09:20:59 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:21:25 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fil(const char **aux, char *c, int *fil)
{
	while (**aux)
	{
		while (**aux == *c)
			(*aux)++;
		if (**aux != '\0')
			(*fil)++;
		while ((**aux != *c) && (**aux))
			(*aux)++;
	}
}

static void	ft_string(char const **s, char *c, const char **aux, size_t *len)
{
	while (**s == *c)
		(*s)++;
	if (**s != '\0')
		*aux = *s;
	while ((**s != *c) && **s)
	{
		(*s)++;
		(*len)++;
	}
}

char		**ft_split(char const *s, char c)
{
	char		**ptr;
	const char	*aux;
	size_t		len;
	int			fil;
	int			i;

	fil = 0;
	len = 0;
	if (!s)
		return (NULL);
	aux = s;
	ft_fil(&aux, &c, &fil);
	if (!(ptr = (char **)malloc((fil + 1) * sizeof(char*))))
		return (NULL);
	aux = s;
	ptr[fil] = NULL;
	i = 0;
	while ((*s) && i < fil)
	{
		ft_string(&s, &c, &aux, &len);
		ptr[i++] = ft_substr(aux, 0, len);
		len = 0;
	}
	return (ptr);
}
