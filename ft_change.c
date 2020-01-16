/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:14:27 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/27 09:08:26 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_change(t_struct *str)
{
	ft_clear(str);
	if (*str->print != '\0')
		ft_flags(str);
	if (*str->print != '\0')
		ft_width(str);
	if (*str->print != '\0')
		ft_precision(str);
	if (*str->print != '\0')
		ft_parse(str);
}
