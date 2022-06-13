/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:47:16 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 21:02:26 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_exit(int x)
{
	(void) x;
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	t_a	enemy;

	move_a(vars, &enemy);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 13 && (vars->m[vars->i - 1][vars->j] != '1'))
		move_up(vars);
	else if (keycode == 0 && (vars->m[vars->i][vars->j - 1] != '1'))
		move_left(vars);
	else if (keycode == 1 && (vars->m[vars->i + 1][vars->j] != '1'))
		move_down(vars);
	else if (keycode == 2 && (vars->m[vars->i][vars->j + 1] != '1'))
		move_right(vars);
	ft_printf ("%d\n", vars->steps);
	return (0);
}
