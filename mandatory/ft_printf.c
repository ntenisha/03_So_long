/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ntenisha <ntenisha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/13 19:47:27 by ntenisha		  #+#	#+#			 */
/*   Updated: 2022/06/13 19:47:28 by ntenisha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "solong.h"

int	write_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	write_hexadecimal(unsigned int i, int base)
{
	char	*arr;
	int		count;
	int		n;

	arr = "0123456789abcdef";
	count = 0;
	n = i % base;
	if (i / base != 0)
		count += write_hexadecimal(i / base, base);
	write(1, &arr[n], 1);
	count++;
	return (count);
}

int	write_decimal(int i)
{
	int	count;

	count = 0;
	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
		count++;
	}
	count += write_hexadecimal(i, 10);
	return (count);
}

int	ft_printf(char *string, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 'd')
				count += write_decimal(va_arg(args, int));
		}
		else
		{
			write(1, &string[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
