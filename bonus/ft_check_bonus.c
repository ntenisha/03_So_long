/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:45:37 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 19:45:39 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

int	ft_check(char *m, t_vars *vars)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (m[i] != '\0')
	{
		if (m[i] != 'C' && m[i] != 'P' && m[i] != '1' && m[i] != '0'
			&& m[i] != 'E' && m[i] != 'A' && m[i] != '\0' && m[i] != '\n')
			return (1);
		else if (m[i] == 'C')
			vars->c = vars->c + 1;
		else if (m[i] == 'P')
			vars->p = vars->p + 1;
		else if (m[i] == 'E')
			vars->e = vars->e + 1;
		i++;
	}
	if (vars->c == 0 || vars->e == 0 || vars->p != 1)
		return (1);
	return (0);
}

int	ft_check_2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->m[i] != NULL)
	{
		j = 0;
		while (vars->m[i][j] != '\0')
		{
			if (vars->m[i][vars->length - 1] != '1' || vars->m[0][j] != '1'
				|| vars->m[i][0] != '1' || vars->m[vars->height - 1][j] != '1')
				return (1);
			if (vars->m[i][j] == 'P')
			{
				vars->i = i;
				vars->j = j;
			}
			j++;
		}
		if (vars->length != j)
			return (1);
		i++;
	}
	return (0);
}
