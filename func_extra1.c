#include "ft_printf.h"

int	ft_putpointer_fd(unsigned long ptr, int fd)
{
	if (!ptr)
		return (write(fd, "0x0", 3)); 
	return (write(fd, "0x", 2) + ft_putnbr_base_fd((int)ptr, "0123456789abcdef", 0, 1));
}

int   ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (1);
        s++;
    }
    return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_unsigned(unsigned int nb, int fd)
{
	int count;

	count = 0;
	if (nb >= 0 && nb < 10)
	{
		nb += '0';
		count += ft_putchar_fd(nb, 1);
	}
	else
	{
		count += ft_unsigned(nb / 10, fd);
		nb = nb % 10 + '0';
		count += ft_putchar_fd(nb, fd);
	}
	return (count);
}
