/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:54:32 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 09:17:19 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *phrase, ...)
{
	int			cont;
	t_struct	str;

	cont = 0;
	va_start(str.ap, phrase);
	str.print = (char *)phrase;
	while (*str.print != '\0')
	{
		if (*str.print == '%' && *(str.print + 1) != '\0')
		{
			str.print++;
			ft_change(&str);
		}
		else
		{
			write(1, str.print, 1);
			str.print++;
			str.len++;
		}
	}
	va_end(str.ap);
	return (str.len);
}
