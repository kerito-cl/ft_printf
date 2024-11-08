/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:15:35 by mquero            #+#    #+#             */
/*   Updated: 2024/11/08 12:37:38 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_int(const char *str, int64_t ar, size_t *i, int *count)
{
	int64_t			a;
	unsigned int	u;

	if (str[*i + 1] == 'c')
	{
		a = ar;
		write(1, &a, 1);
		*count = *count + 1;
		*i = *i + 1;
	}
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		a = ar;
		*count = *count + ft_putnbr_fd((int)a, 1, 1);
		*i = *i + 1;
	}
	else if (str[*i + 1] == 'u')
	{
		u = ar;
		*count = *count + ft_putnbr_fd(u, 1, 1);
		*i = *i + 1;
	}
}

void	handle_hex(const char *str, uint64_t ar, size_t *i, int *count)
{
	void	*s;

	if (str[*i + 1] == 'p')
	{
		s = (void *)ar;
		if (s == NULL)
		{
			write(1, "(nil)", 5);
			*count = *count + 5;
		}
		else
		{
			write(1, "0x", 2);
			*count = *count + ft_printhex((uintptr_t)s, str[*i + 1], 1) + 2;
		}
		*i = *i + 1;
	}
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
	{
		*count = *count + ft_printhex((unsigned int)ar, str[*i + 1], 1);
		*i = *i + 1;
	}
}

void	handle_str(const char *str, char *ar, size_t *i, int *count)
{
	char	*s;

	if (str[*i + 1] == 's')
	{
		s = ft_strdup(ar);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			*count = *count + 6;
		}
		else
		{
			write(1, s, ft_strlen(s));
			*count = *count + ft_strlen(s);
		}
		free(s);
		*i = *i + 1;
	}
	else if (str[*i + 1] == '%')
	{
		write(1, &str[*i + 1], 1);
		*count = *count + 1;
		*i = *i + 1;
	}
}

void	handle_restofstr(const char *str, size_t *i, int *count)
{
	write(1, &str[*i], 1);
	*count = *count + 1;
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
				|| str[i + 1] == 'i' || str[i + 1] == 'u'))
			print_int(str, va_arg(args, int64_t), &i, &count);
		else if (str[i] == '%' && (str[i + 1] == 's'
				|| str[i + 1] == '%'))
			handle_str(str, va_arg(args, char *), &i, &count);
		else if (str[i] == '%' && (str[i + 1] == 'p' || str[i + 1] == 'x'
				|| str[i + 1] == 'X'))
			handle_hex(str, va_arg(args, uint64_t), &i, &count);
		else
			handle_restofstr(str, &i, &count);
		i++;
	}
	va_end(args);
	return (count);
}
