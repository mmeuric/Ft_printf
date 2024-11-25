/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:44:51 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/25 15:51:04 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lenadrr(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	write_ptr(unsigned long long addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		write_ptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

int	prt_ptr(void *addr)
{
	if (addr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	write_ptr((unsigned long long)addr);
	return (ft_lenadrr((unsigned long long)addr) + 2);
}
