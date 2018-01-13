/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflstadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:04:07 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 19:06:16 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printflstadd(t_plist **alst, t_plist *new)
{
	t_plist *current;

	if (!new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
