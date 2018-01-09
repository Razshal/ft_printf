/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:08:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 15:17:56 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_max_countdigit_base(intmax_t n, int base)
{
	int count;

	count = 0;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count + 1);
}