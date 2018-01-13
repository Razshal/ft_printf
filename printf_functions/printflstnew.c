/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:02:39 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 19:08:19 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_plist	*printflstnew(void *arg)
{
	t_plist	*newlist;

	newlist = NULL;
	if (!(newlist = (t_plist*)malloc(sizeof(t_plist))))
		return (NULL);
	if (arg)
		newlist->arg = arg;
	else
		newlist->arg = NULL;
	newlist->flag = ft_strnew(4);
	newlist->width = 0;
	newlist->precision = -1;
	newlist->length = ft_strnew(2);
	newlist->type = -1;
	newlist->isrealarg = 0;
	newlist->ischarexception = 0;
	newlist->next = NULL;
	return (newlist);
}
