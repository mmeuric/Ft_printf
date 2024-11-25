/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:00:32 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/25 15:19:24 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

static int	ft_convert(char spec_char, va_list args)
{
	if (spec_char == '%')
		return (write(1, "%", 1));
	else if (spec_char == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (spec_char == 's')
		return (prt_str(va_arg(args, char *)));
	else if (spec_char == 'p')
		return (prt_ptr(va_arg(args, void *)));
	else if (spec_char == 'd' || spec_char == 'i')
		return (prt_int(va_arg(args, int)));
	else if (spec_char == 'u')
		return (prt_unsigned(va_arg(args, unsigned int)));
	else if (spec_char == 'x')
		return (prt_hexa(va_arg(args, ssize_t), false));
	else if (spec_char == 'X')
		return (prt_hexa(va_arg(args, ssize_t), true));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_convert(str[i], args);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
