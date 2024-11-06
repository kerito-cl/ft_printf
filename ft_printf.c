#include "./libft/libft.h"
#include  <stdarg.h>
#include  <stdio.h>

void	hexa_letter_putchar(int divisor)
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
void	itohex(int p)
{
	int	divisor;
	int	reminder;
	int	i;
	int	hold;

	i = 0;
	divisor = p;
	while ((divisor / 16) >= 16)
	{
		divisor = divisor / 16;
		i++;
	}
	divisor = divisor / 16;
	if (divisor > 9)
		hexa_letter_putchar(divisor);
	else
		ft_putnbr_fd(divisor, 1);
	reminder = i + 1;
	hold = divisor;
	while (i >= 0)
	{
		divisor = divisor * 16;
		i--;
	}
	if ((p - divisor / 16) > 0)
		itohex(p - divisor);
	else if (reminder > 0)
		ft_putnbr_fd(reminder + 1, 1);


}
int ft_printf(const char *buffer, ...)
{
  size_t i;
  va_list args;
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
		    ft_putnbr_fd(va_arg(args ,int), 1);
		    i++;
	    }
	    else if (buffer[i + 1] == 'u')
	    {
		    ft_putnbr_fd(va_arg(args ,unsigned int), 1);
		    i++;
	    }
	    else if (buffer[i + 1] == 's')
	    {
		    char	*s = va_arg(args, char *);
		    ft_putstr_fd(s, 1);
		    i++;
	    }
	/*    else if (buffer[i + 1] == 'p')
		    char	*s = va_arg(args, char *);*/
	    
    } 
    else 
	    ft_putchar_fd(buffer[i], 1);
    i++;
  }
  va_end(args);
  return 0;
}
 

int main()
{
	char	*s = "this is my string argument";
  //ft_printf("hola %c %c %c %d, %u are my arguments and %s \n", 'a', 'b', 'c', 3, 134, s);
  //printf("hola %c, %c, %c, %d, %u, %p are my arguments and %s\n", 'a', 'b','c', 3, 123, s);
   itohex(1478);

}

