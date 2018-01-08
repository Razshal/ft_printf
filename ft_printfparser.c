/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:26:34 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/08 15:18:57 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdarg.h>

static int		assign_digit(const char *format, int count, t_plist *list)
{
	if (format[count - 1] == '.')
	{
		if (!ft_isdigit(format[count]))
			list->precision = 1;
		else
			list->precision = ft_atoi(&format[count]);
	}
	else
		list->width = ft_atoi(&format[count]);
	while (format[count] && ft_isdigit(format[count]))
		count++;
	return (count);
}

static int		assign_length(const char *format, int count, t_plist *list)
{
	char c;
	list->length[0] = format[count++];
	if (ft_is_printf_length(format[count])
			&& (c = format[count]) && (c == 'l' || c == 'h')
			&& format[count - 1] == c)
		{
			list->length[1] = c;
			count++;
		}
	else
		list->length[1] = '\0';
	return (count);
}

static int		parse_flags(const char *format, int count, t_plist *list)
{
	int lcount;

	lcount = 0;
	while (ft_is_printf_flag(format[count]))
	{
		if (!ft_strchr(list->flag, format[count]))
			list->flag[lcount++] = format[count];
		count++;
	}
	return (count);
}

static int		parse_one(t_plist **list, const char *format)
{
	int count;
	t_plist *current;

	count = 0;
	current = ft_printflistnew(NULL);
	if (ft_is_printf_flag(format[count]))
		count = parse_flags(format, count, current);
	if (ft_isdigit(format[count]))
		count = assign_digit(format, count, current);
	while ((format[count] && format[count] == '.' && format[count + 1]
			&& ft_isdigit(format[count + 1])) || format[count] == '.')
		count = assign_digit(format, ++count, current);
	while (format[count] && ft_is_printf_length(format[count]))
		count = assign_length(format, count, current);
	while (format[count] && !ft_is_printf_type(format[count]))
		count++;
	if (ft_is_printf_type(format[count]))
	{
		current->type = format[count++];
		current->isrealarg = 1;
	}
	ft_printflstadd(list, current);
	return (count);
}

t_plist		*parse_input(const char *format)
{
	int		count;
	int		cutcount;
	t_plist	*local;

	count = -1;
	cutcount = 0;
	local = NULL;
	if (format[0] == '\0')
		return (NULL);
	while (format[++count])
	{
		if (format[count] == '%')
		{
			if (count > 0)
			{
				ft_printflstadd(&local,
						ft_printflststr(format, cutcount, count));
			}
			count++;
			count = count + parse_one(&local, &format[count]);
			cutcount = count;
		}
	}
	ft_printflstadd(&local, ft_printflststr(format, cutcount, count));
	return (local);
}
