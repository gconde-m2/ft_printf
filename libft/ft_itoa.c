/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:53:48 by alaguila          #+#    #+#             */
/*   Updated: 2019/12/26 11:48:18 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_len(char *sign, long int *n, long int *nb, long int *nb2)
{
	int cont;

	cont = 0;
	if (*n < 0)
	{
		*sign = '-';
		*nb = *nb * -1;
		*nb2 = *nb;
		cont++;
	}
	while (*nb > 9)
	{
		cont++;
		*nb = *nb / 10;
	}
	return (cont);
}

char		*ft_itoa(long int n)
{
	char		sign;
	long int	nb;
	int			cont;
	long int	nb2;
	char		*ptr;

	cont = 0;
	nb = n;
	nb2 = nb;
	cont = ft_size_len(&sign, &n, &nb, &nb2);
	cont++;
	if ((ptr = malloc(sizeof(char) * (cont + 1))) == NULL)
		return (NULL);
	if (sign == '-')
		ptr[0] = sign;
	ptr[cont] = '\0';
	while (nb2 > 9)
	{
		ptr[cont - 1] = (nb2 % 10) + '0';
		nb2 = nb2 / 10;
		cont--;
	}
	ptr[cont - 1] = nb2 + '0';
	return (ptr);
}
