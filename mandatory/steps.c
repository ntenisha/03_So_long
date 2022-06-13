/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:48:05 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 19:48:06 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_len_10(long long x)
{
	int	count;

	count = 1;
	while ((x / 10) != 0)
	{
		count++;
		x /= 10;
	}
	return (count);
}

char	*f_ioa(int min, int count, int n, char *str)
{
	if (min == -1)
	{
		while (count >= 1)
		{
			str[count] = ((-1) * (long long)n % 10) + '0';
			count --;
			n /= 10;
		}
		str[count] = '-';
		return (str);
	}
	else if (min == 1)
	{
		while (count >= 0)
		{
			str[count] = ((long long)n % 10) + 48;
			count --;
			n /= 10;
		}
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	int			min;
	long long	x;
	int			count;
	char		*str;

	min = 1;
	x = (long long) n;
	count = ft_len_10 (x);
	if (n < 0)
	{
		count++;
		min = -1;
	}
	str = (char *) malloc (sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	count --;
	return (f_ioa(min, count, n, str));
}

int	ft_strlenx(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlenx(s1)
				+ ft_strlenx(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[k++] = s2[i++];
	str[k] = '\0';
	return (str);
}
