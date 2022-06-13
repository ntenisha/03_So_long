/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntenisha <ntenisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:47:55 by ntenisha          #+#    #+#             */
/*   Updated: 2022/06/13 21:18:11 by ntenisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H 
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_data {
	void	*img;
	void	*img1;
	void	*img0;
	void	*imgp;
	void	*imgc;
	void	*imge;
	void	*imga;
	char	*addr;
	char	*relative_pathe;
	char	*relative_path1;
	char	*relative_path0;
	char	*relative_pathp;
	char	*relative_pathc;
	char	*relative_pathe1;
	char	*relative_patha;
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**m;
	int		size;
	int		i;
	int		j;
	int		length;
	int		height;
	int		c;
	int		p;
	int		e;
	int		steps;
	int		fd;
	t_data	*img;
}	t_vars;

typedef struct s_params {
	int		f;
	int		l;
	int		d;
	int		k;
	char	*num;
	char	*str;
}	t_params;

typedef struct s_a {
	int	i;
	int	j;
}	t_a;

int		ft_check(char *m, t_vars *vars);
int		ft_check_2(t_vars *vars);
int		ft_count(char const *s, char c);
int		ft_len(char *strr, char c);
char	**add_words_to_str(char const *s, char c, char **str, t_vars *vars);
char	**ft_split(char const *s, char c, t_vars *vars);
char	**ft_free(char **v, int h);
char	*ft_substr(char *s, int start, size_t len);
int		ft_strlen(const char *s);
void	ft_read1(int fd, int *ret, char *buf, int x);
char	*get_next_line1(int fd);
int		key_hook(int keycode, t_vars *vars);
int		ft_render(t_vars *vars);
void	images(t_data *img, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		ft_exit(int x);
void	move_up(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_down(t_vars *vars);
void	move_a(t_vars *vars, t_a *atack);
int		ft_len_10(long long x);
char	*f_ioa(int min, int count, int n, char *str);
char	*ft_itoa(int n);
int		ft_strlenx(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_show_score(t_params	*params, t_vars *vars);
void	ft_show(t_vars *vars, t_data *img, t_params *params);
int		ft_printf(char *string, ...);
#endif