/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 15:22:11 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 15:22:13 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse(char *s)
{
	char *s_end;
	char c;

	s_end = s + ft_strlen(s) - 1;
	while (s < s_end)
	{
		c = *s;
		*s++ = *s_end;
		*s_end-- = c;
	}
}

static int	ft_countchars(int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
		i++;
	else
	{
		while (n > 0)
		{
			i++;
			n /= 10;
		}
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	unsigned int	x;
	int				sign;
	char			*buf;

	buf = ft_strnew(ft_countchars(n));
	x = n;
	if ((sign = n) < 0)
		x = -n;
	i = 0;
	if (x == 0)
		buf[i++] = '0';
	while (x > 0)
	{
		buf[i++] = x % 10 + '0';
		x /= 10;
	}
	if (sign < 0)
		buf[i++] = '-';
	buf[i] = '\0';
	ft_reverse(buf);
	return (buf);
}
