/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:47:36 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 20:08:10 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*line;

	vars.size = 32;
	vars.fd = open(argv[1], O_RDONLY);
	line = get_next_line1(vars.fd);
	vars.m = ft_split(line, '\n', &vars);
	if (argc != 2 || ft_check(line, &vars) == 1 || ft_check_2(&vars) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.size * vars.length,
			vars.size * (vars.height), "So_Long");
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, ft_exit, NULL);
	vars.img = malloc(sizeof(t_data));
	images(vars.img, &vars);
	mlx_loop_hook(vars.mlx, ft_render, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
