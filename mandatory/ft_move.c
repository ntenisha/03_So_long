/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:47:21 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 19:47:22 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_a(t_vars *vars, t_a *atack)
{
	static int	k = 1;

	atack->i = 0;
	while (vars->m[atack->i] != NULL)
	{
		atack->j = 0;
		while (vars->m[atack->i][atack->j] != '\0')
		{
			if (vars->m[atack->i][atack->j] == 'A' && k % 2 == 0
			&& vars->m[atack->i][atack->j + 1] == '0')
			{
				vars->m[atack->i][atack->j + 1] = 'A';
				vars->m[atack->i][atack->j] = '0';
			}
			else if (vars->m[atack->i][atack->j] == 'A'
			&& k % 2 != 0 && vars->m[atack->i][atack->j - 1] == '0')
			{
				vars->m[atack->i][atack->j - 1] = 'A';
				vars->m[atack->i][atack->j] = '0';
			}
			atack->j++;
		}
		atack->i++;
	}
	k++;
}

void	move_up(t_vars *vars)
{
	if (vars->m[vars->i - 1][vars->j] == 'C')
	{
		vars->m[vars->i - 1][vars->j] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->i = vars->i - 1;
		vars->c = vars->c - 1;
		vars->steps = vars->steps + 1;
	}
	else if (vars->m[vars->i - 1][vars->j] == '0')
	{
		vars->m[vars->i - 1][vars->j] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->i = vars->i - 1;
		vars->steps = vars->steps + 1;
	}
	else if ((vars->m[vars->i - 1][vars->j] == 'E' && vars->c == 0)
			|| vars->m[vars->i - 1][vars->j] == 'A')
	{
		vars->steps = vars->steps + 1;
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

void	move_left(t_vars *vars)
{
	if (vars->m[vars->i][vars->j - 1] == 'C')
	{
		vars->m[vars->i][vars->j - 1] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->j = vars->j - 1;
		vars->c = vars->c - 1;
		vars->steps = vars->steps + 1;
	}
	else if (vars->m[vars->i][vars->j - 1] == '0')
	{
		vars->m[vars->i][vars->j - 1] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->j = vars->j - 1;
		vars->steps = vars->steps + 1;
	}
	else if ((vars->m[vars->i][vars->j - 1] == 'E' && vars->c == 0)
			|| vars->m[vars->i][vars->j - 1] == 'A')
	{
		vars->steps = vars->steps + 1;
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->m[vars->i][vars->j + 1] == 'C')
	{
		vars->m[vars->i][vars->j + 1] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->j = vars->j + 1;
		vars->c = vars->c - 1;
		vars->steps = vars->steps + 1;
	}
	else if (vars->m[vars->i][vars->j + 1] == '0')
	{
		vars->m[vars->i][vars->j + 1] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->j = vars->j + 1;
		vars->steps = vars->steps + 1;
	}
	else if ((vars->m[vars->i][vars->j + 1] == 'E' && vars->c == 0)
			|| vars->m[vars->i][vars->j + 1] == 'A')
	{
		vars->steps = vars->steps + 1;
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

void	move_down(t_vars *vars)
{
	if (vars->m[vars->i + 1][vars->j] == 'C')
	{
		vars->m[vars->i + 1][vars->j] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->i = vars->i + 1;
		vars->c = vars->c - 1;
		vars->steps = vars->steps + 1;
	}
	else if (vars->m[vars->i + 1][vars->j] == '0')
	{
		vars->m[vars->i + 1][vars->j] = 'P';
		vars->m[vars->i][vars->j] = '0';
		vars->i = vars->i + 1;
		vars->steps = vars->steps + 1;
	}
	else if ((vars->m[vars->i + 1][vars->j] == 'E' && vars->c == 0) ||
			vars->m[vars->i + 1][vars->j] == 'A')
	{
		vars->steps = vars->steps + 1;
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}
