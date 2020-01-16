/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:35:47 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/26 12:54:12 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(t_struct *str)
{
	if (*str->print == 'c')
		ft_char(str);
	if (*str->print == 's')
		ft_string(str);
	if (*str->print == 'd' || *str->print == 'i')
		ft_number(str);
	if (*str->print == 'u')
		ft_numberu(str);
	if (*str->print == 'p')
		ft_direc(str);
	if (*str->print == 'x')
		ft_printx(str);
	if (*str->print == 'X')
		ft_printaltx(str);
	if (*str->print == '%')
		ft_percent(str);
	str->print++;
}
