/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 08:51:18 by gloukas           #+#    #+#             */
/*   Updated: 2023/03/13 12:19:25 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ppos
{
	int			px;
	int			py;
}				t_ppos;

typedef struct s_epos
{
	int			ex;
	int			ey;
}				t_epos;

typedef struct s_loopy
{
	int			i;
	int			j;
}				t_loopy;

typedef struct s_found
{
	int			i;
	int			j;
	int			p;
	int			e;
	int			c;
}				t_found;

typedef struct s_lenght
{
	int			x;
	int			y;
}				t_lenght;

typedef struct s_reg
{
	int			*t;
	int			n;
	int			s;
	int			k;
	int			m;
}				t_reg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*wind;
	char		**area;
	t_lenght	size;
	t_ppos		p;
	t_epos		e;
	int			col;
	int			move;
	char		**areacopy;
	void		*player;
	void		*collect;
	void		*space;
	void		*exit_0;
	void		*exit_1;
	void		*wall0_0;
	void		*wall0_1;
	void		*wall0_x;
	void		*wall1_0;
	void		*wallin;
	void		*wall1_x;
	void		*wallx_0;
	void		*wallx_1;
	void		*wallx_x;
	int			h;
	int			w;
	void		*audio;
}				t_mlx;

//check_base_map.c
//good
int				ft_check_param_and_exist(int ac, char **av);
void			ft_check_if_rectangular(char *s, struct s_mlx ptr);
void			ft_check_characters(struct s_mlx ptr);
void			ft_check_if_close(struct s_mlx ptr);
void			ft_check_cep(struct s_mlx ptr);

//help_check.c
//good
struct s_mlx	ft_counint(char *s);
struct s_mlx	ft_count_collec(struct s_mlx ptr);
struct s_mlx	rev_search_p(struct s_mlx ptr);
struct s_mlx	rev_search_e(struct s_mlx ptr);
void			ft_free(char **t, int n);

//check_path.c
//good
char			**ft_copy_area(struct s_mlx ptr);
void			rev_path_c(char **s, int x, int y, struct s_mlx ptr);
void			rev_path_e(char **s, int x, int y, struct s_mlx ptr);
void			rev_path_collec(char **s, struct s_mlx ptr);
void			ft_check_path(struct s_mlx ptr);

//main_check.c
//good
void			ft_check_extension(char *s);
struct s_mlx	make_area(char *zone, struct s_mlx ptr);
struct s_mlx	ft_check_all(int ac, char *av[]);

//start_mlx.c
void			*syntax_creation(void *texture, char *name);
t_mlx			*creation_textures(t_mlx *ptr);
void			full_wall(t_mlx *ptr, t_loopy index);
struct s_mlx	display_all(struct s_mlx *ptr);
//test
int				my_key_funct(int keycode, struct s_mlx *ptr);
void			move_w(t_mlx *ptr, int *move);
void			move_a(t_mlx *ptr, int *move);
void			move_d(t_mlx *ptr, int *move);
void			move_s(t_mlx *ptr, int *move);

//waloo
void			wingame(struct s_mlx *ptr);
void			ft_sleep(void);
struct s_mlx	ft_loop(int keycode, struct s_mlx ptr);

#endif
