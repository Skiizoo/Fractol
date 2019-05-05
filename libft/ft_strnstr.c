/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 15:27:37 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 15:29:35 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	nlen;
	int		lastresult;

	if (*needle == '\0')
		return ((char*)haystack);
	nlen = ft_strlen(needle);
	lastresult = 1;
	while (nlen <= hlen && *haystack != '\0'
		&& (lastresult = ft_strncmp(haystack, needle, nlen)))
	{
		hlen--;
		haystack++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)haystack);
}
