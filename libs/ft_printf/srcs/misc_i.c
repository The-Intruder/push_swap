/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:35:08 by mnaimi            #+#    #+#             */
/*   Updated: 2021/12/12 23:36:01 by mnaimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* -------------------------------------------------------------------------- */

void	ft_putnchar(char c, size_t n, int *outpt_len)
{
	*outpt_len += n;
	while (n-- != 0)
		write(1, &c, 1);
}

/* -------------------------------------------------------------------------- */

void	ft_putstr(char *s, int *outpt_len)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*outpt_len += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		*outpt_len += ft_strlen(s);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putstr_len(char *s, size_t len, int *outpt_len)
{
	if (s == NULL)
		write(1, "(null)", len);
	else
		write(1, s, len);
	*outpt_len += len;
}

/* -------------------------------------------------------------------------- */

void	ft_puthex_adrs(unsigned long n, int *outpt_len)
{
	if (n < 10)
		ft_putchar(n + 48, outpt_len);
	else if (n >= 10 && n <= 15)
		ft_putchar(n + 87, outpt_len);
	else if (n > 15)
	{
		ft_puthex_adrs(n / 16, outpt_len);
		ft_puthex_adrs(n % 16, outpt_len);
	}
}

/* -------------------------------------------------------------------------- */

void	ft_putchar(char c, int *outpt_len)
{
	write(1, &c, 1);
	*outpt_len += 1;
}

/* -------------------------------------------------------------------------- */