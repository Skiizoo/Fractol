/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tbroggi <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/15 15:22:48 by tbroggi      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/15 15:22:52 by tbroggi     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content)
		newlst->content = ft_memalloc((size_t)(sizeof(content) * content_size));
	else
		content = NULL;
	if (newlst->content)
		ft_memcpy(newlst->content, content, content_size);
	if (content)
		newlst->content_size = content_size;
	else
		content_size = 0;
	newlst->next = NULL;
	return (newlst);
}
