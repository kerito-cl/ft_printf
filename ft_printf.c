#include "./libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void	hexa_capital_putchar(int divisor)
{
	if (divisor > 9)
	{
		if (divisor == 10)
			write(1, "A", 1);
		else if (divisor == 11)
			write(1, "B", 1);
		else if (divisor == 12)
			write(1, "C", 1);
		else if (divisor == 13)
			write(1, "D", 1);
		else if (divisor == 14)
			write(1, "E", 1);
		else if (divisor == 15)
			write(1, "F", 1);
	}
	else if (divisor < 10)
		ft_putnbr_fd(divisor, 1);
}
void	hexa_letter_putchar(int divisor)
{
	if (divisor > 9)
	{
		if (divisor == 10)
			write(1, "a", 1);
		else if (divisor == 11)
			write(1, "b", 1);
		else if (divisor == 12)
			write(1, "c", 1);
		else if (divisor == 13)
			write(1, "d", 1);
		else if (divisor == 14)
			write(1, "e", 1);
		else if (divisor == 15)
			write(1, "f", 1);
	}
	else if (divisor < 10)
		ft_putnbr_fd(divisor, 1);
}
void	ft_printhex(size_t p, char x)
{
	size_t	quotient;
	int		i;
	int		remainder;

	i = 0;
	quotient = p;
	remainder = quotient % 16;
	if ((quotient / 16) != 0)
	{
		ft_printhex(quotient / 16, x);
	}
	if (x == 'x' || x == 'p')
		hexa_letter_putchar(remainder);
	else
		hexa_capital_putchar(remainder);
}
int	ft_printf(const char *buffer, ...)
{
	size_t	i;
	va_list	args;
	char	*s;

	va_start(args, buffer);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '%')
		{
			if (buffer[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				i++;
			}
			else if (buffer[i + 1] == 'd' || buffer[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(args, int), 1);
				i++;
			}
			else if (buffer[i + 1] == 'u')
			{
				ft_putnbr_fd(va_arg(args, unsigned int), 1);
				i++;
			}
			else if (buffer[i + 1] == 's')
			{
				s = ft_strdup(va_arg(args, char *));
				write(1, s, ft_strlen(s));
				free(s);
				i++;
			}
			else if (buffer[i + 1] == 'p')
			{
				write(1, "0x", 2);
				ft_printhex(va_arg(args, size_t), buffer[i + 1]);
				i++;
			}
			else if (buffer[i + 1] == 'x' || buffer[i + 1] == 'X')
			{
				ft_printhex(va_arg(args, size_t), buffer[i + 1]);
				i++;
			}
		}
		else
			ft_putchar_fd(buffer[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	char			*s = "ver";
	unsigned int	a;
	int				b;

	a = 1233435122;
	b = 40967;
	/*printf("%X\n", a);
	printf("%X\n", b);
	ft_printf("%X\n", a);
	ft_printf("%X\n", b);*/

	/*ft_printf("quiero %s si: %p, %c, %d crashea \n", s, s, 'd', 'a');
	printf("quiero %s si: %p, %c, %d crashea \n", s, s, 'd', 'a') ;*/

	ft_printf("%x", s);
}
