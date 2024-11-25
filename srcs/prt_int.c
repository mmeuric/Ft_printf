/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:16:50 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/25 14:21:29 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_lennbr(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	write_int(int n)
{
	static char	digits[] = "0123456789";

	if (n > 9)
		write_int(n / 10);
	write(1, &digits[n % 10], 1);
}

int	prt_int(int n)
{
	int	len;

	if (n == INT_MIN)
		return ((write(1, "-2147483648", 11)));
	len = ft_lennbr(n);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	write_int(n);
	return (len);
}
