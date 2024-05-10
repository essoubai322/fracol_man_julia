/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebaai <asebaai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:18:30 by asebaai           #+#    #+#             */
/*   Updated: 2024/05/10 10:30:07 by asebaai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	atoi_with_counter(const char *nptr, int *i, int *sign)
{
	int	res;

	res = 0;
	while ((nptr[*i] >= 9 && nptr[*i] <= 13) || nptr[*i] == 32)
		(*i)++;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
	while ((nptr[*i] >= '0' && nptr[*i] <= '9') && nptr[*i])
	{
		res *= 10;
		res += (nptr[*i] - '0');
		(*i)++;
	}
	return (res);
}

static void	apa(const char *s, int i, int a)
{
	if (s[i] == '.')
		woopsies();
	if (a == 1)
	{
		while (s[i])
		{
			if (!(s[i] >= '0' && s[i] <= '9') && s[i] && s[i] != ' ')
				woopsies();
			i++;
		}
	}
	if (a == 2)
	{
		while (s[i])
		{
			if (s[i] >= '0' && s[i] <= '9')
				woopsies();
			i++;
		}
	}
}

double	ft_atof(const char *s)
{
	int		i;
	int		sign;
	double	res;
	double	dp;

	sign = 1;
	i = 0;
	dp = 1;
	apa(s, i, 0);
	res = atoi_with_counter(s, &i, &sign);
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			dp /= 10;
			res += (s[i] - 48) * dp;
			i++;
			apa(s, i, 1);
		}
	}
	apa(s, i, 2);
	return (res * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && n - 1 > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
