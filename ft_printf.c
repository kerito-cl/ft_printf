#include "./libft/libft.h"
#include  <stdarg.h>
#include  <stdio.h>

int ft_printf(const char *buffer, ...)
{
  int i;
  va_list args;
  va_start(args, buffer);
  int p  = va_arg(args, int);

  i = 0;
  while (buffer[i] != '\0') 
  {
    if (buffer[i] == '%') 
    {
      if (buffer[i + 1] == 'c')
        ft_putchar_fd( p , 1);
    } 
        i++;
    }
    va_end(args);
}
 

int main()
{
  ft_printf("%c", 'a');
}
