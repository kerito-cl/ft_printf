/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:15:35 by mquero            #+#    #+#             */
/*   Updated: 2024/11/07 19:15:37 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

void	hexa_putchar(int divisor, char x)
{
	char	c;

	c = divisor + 55;
	if (divisor > 9 && x == 'X')
		write(1, &c, 1);
	else if (divisor > 9 && (x == 'x' || x == 'p'))
	{
		c = ft_tolower(c);
		write(1, &c, 1);
	}
	else if (divisor < 10)
		ft_putnbr_fd(divisor, 1, 1);
}

int	ft_printhex(uint64_t p, char x, int count)
{
	uint64_t	quotient;
	uint64_t	remainder;

	quotient = p;
	remainder = quotient % 16;
	if ((quotient / 16) != 0)
		count = ft_printhex(quotient / 16, x, count + 1);
	hexa_putchar(remainder, x);
	return (count);
}
void  print_int(const char  *str , size_t *i, int *count, ...)
{
  va_list	args;

	va_start(args, str);
  			if (str[*i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				*count += 1;
				*i++;
			}
va_end(args);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	char	*s;
	int		count;
	int		hold;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			/*if (str[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				count += 1;
				i++;
			}*/
      print_int(str, &i, &count, args);
			if (str[i + 1] == 'd' || str[i + 1] == 'i')
			{
				hold = va_arg(args, int);
				count += ft_putnbr_fd(hold, 1, 1);
				i++;
			}
			else if (str[i + 1] == 'u')
			{
				hold = va_arg(args, unsigned int);
				count += ft_putnbr_fd(hold, 1, 1);
				i++;
			}
			else if (str[i + 1] == 's')
			{
				s = ft_strdup(va_arg(args, char *));
				if (s == NULL)
				{
					write(1, "(null)", 6);
					count += 6;
				}
				else
				{
					write(1, s, ft_strlen(s));
					count += ft_strlen(s);
				}
				free(s);
				i++;
			}
			else if (str[i + 1] == 'p')
			{
				s = va_arg(args, void *);
				if (s == NULL)
				{
					write(1, "(nil)", 5);
					count += 5;
				}
				else
				{
					write(1, "0x", 2);
					count += ft_printhex((uintptr_t)s, str[i + 1], 1) + 2;
				}
				i++;
			}
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
			{
				count += ft_printhex(va_arg(args, unsigned int), str[i + 1], 1);
				i++;
			}
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}
int	main(void)
{
	char			*s = "hola";
	int				b = 2;
	unsigned int				c = 3;
  void  *ptr;
  int d;

  ft_printf("%d\n", 123);
}
