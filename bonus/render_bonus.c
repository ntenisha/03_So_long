/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:46:46 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 19:46:47 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong_bonus.h"

void	images(t_data *img, t_vars *vars)
{
	img->relative_pathe = "./pictures/exit.xpm";
	img->relative_path1 = "./pictures/1.xpm";
	img->relative_path0 = "./pictures/0.xpm";
	img->relative_pathp = "./pictures/c1.xpm";
	img->relative_pathc = "./pictures/p.xpm";
	img->relative_pathe1 = "./pictures/exit1.xpm";
	img->relative_patha = "./pictures/A.xpm";
	img->img = mlx_xpm_file_to_image(vars->mlx, img->relative_pathe,
			&img->img_width, &img->img_height);
	img->img1 = mlx_xpm_file_to_image(vars->mlx, img->relative_path1,
			&img->img_width, &img->img_height);
	img->img0 = mlx_xpm_file_to_image(vars->mlx, img->relative_path0,
			&img->img_width, &img->img_height);
	img->imgp = mlx_xpm_file_to_image(vars->mlx, img->relative_pathp,
			&img->img_width, &img->img_height);
	img->imgc = mlx_xpm_file_to_image(vars->mlx, img->relative_pathc,
			&img->img_width, &img->img_height);
	img->imge = mlx_xpm_file_to_image(vars->mlx, img->relative_pathe1,
			&img->img_width, &img->img_height);
	img->imga = mlx_xpm_file_to_image(vars->mlx, img->relative_patha,
			&img->img_width, &img->img_height);
}

void	ft_show(t_vars *vars, t_data *img, t_params *params)
{
	if (vars->m[params->f][params->d] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->img1, params->k, params->l);
	else if (vars->m[params->f][params->d] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->img0, params->k, params->l);
	else if (vars->m[params->f][params->d] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->imgc, params->k, params->l);
	else if (vars->m[params->f][params->d] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->imgp, params->k, params->l);
	else if (vars->m[params->f][params->d] == 'A')
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->imga, params->k, params->l);
	else if (vars->m[params->f][params->d] == 'E' && vars->c != 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->img, params->k, params->l);
	else if (vars->m[params->f][params->d] == 'E' && vars->c == 0)
		mlx_put_image_to_window(vars->mlx, vars->win,
			img->imge, params->k, params->l);
}

void	ft_show_score(t_params	*params, t_vars *vars)
{
	params->num = ft_itoa(vars->steps);
	params->str = ft_strjoin("Moves = ", params->num);
	mlx_string_put(vars->mlx, vars->win, 0, vars->height * 32,
		0xFFD700, params->str);
	free(params->num);
	free(params->str);
}

int	ft_render(t_vars *vars)
{
	t_params	params;

	params.f = 0;
	params.l = 0;
	mlx_clear_window(vars->mlx, vars->win);
	while (vars->m[params.f] != NULL)
	{
		params.d = 0;
		params.k = 0;
		while (vars->m[params.f][params.d] != '\0')
		{
			ft_show(vars, vars->img, &params);
			params.d++;
			params.k += 32;
		}
		params.f++;
		params.l += 32;
	}
	ft_show_score(&params, vars);
	return (0);
}
