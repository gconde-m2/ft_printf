/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gconde-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:58:54 by gconde-m          #+#    #+#             */
/*   Updated: 2019/12/30 09:20:16 by gconde-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_struct
{
	int		i;
	int		len;
	char	*print;
	va_list	ap;
	int		flag;
	int		w;
	int		pre;
	char	*saving;
	int		cont;
	int		paco;
	char	*flagchar;
	int		p;
	int		memflag;
}				t_struct;

int				ft_printf(const char *phrase, ...);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
void			ft_parse(t_struct *str);
void			ft_char(t_struct *str);
void			ft_parse(t_struct *str);
void			ft_putchar(char c);
void			ft_string(t_struct *str);
int				ft_atoi(const char *str);
void			ft_number(t_struct *str);
void			ft_putnbr(int nb);
void			ft_direc(t_struct *str);
char			*ft_itoa(long int n);
void			ft_printx(t_struct *str);
char			*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
char			*ft_strnew(size_t size);
void			ft_change(t_struct *str);
void			ceroflag(t_struct *str);
void			minusflag(t_struct *str);
void			ft_flags(t_struct *str);
void			ft_clear(t_struct *str);
void			ft_width(t_struct *str);
void			charminus(char c, t_struct *str);
void			stringwidth1(t_struct *str, const char *c);
void			stringwidth2(t_struct *str, const char *c);
void			ft_numberu(t_struct *str);
void			numberminus(long int c, t_struct *str, const char *k, int len);
void			numbercero(long int c, t_struct *str, const char *k, int len);
void			ft_printaltx(t_struct *str);
void			memorycero(int c, t_struct *str, char *k, int lenpre);
void			ft_widthstar(t_struct *str);
void			ft_precision(t_struct *str);
void			ft_precisionstar(t_struct *str);
void			ft_putstr_n(char *s, int fd, long int n);
void			numberceronega(int c, t_struct *str, const char *k);
void			numberprec(long int c, t_struct *str, const char *k,
				int lenpre);
void			numberprecwidth(long int c, t_struct *str, const char *k,
				int len);
void			putminuscero(int one, int two, char *flag);
void			tryallcases(int c, t_struct *str, char *k, int lenpre);
void			numberminusx(unsigned int c, t_struct *str, char k, int len);
void			numbercerox(unsigned int c, t_struct *str, char k, int len);
void			numberprecx(unsigned int c, t_struct *str, char k, int lenpre);
void			numberprecwidthx(unsigned int c, t_struct *str, char k,
				int len);
void			ft_putnbrmemory(unsigned int nb, char c, t_struct *str);
void			ft_percent(t_struct *str);

#endif
