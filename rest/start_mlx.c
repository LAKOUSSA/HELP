/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 08:56:41 by gloukas           #+#    #+#             */
/*   Updated: 2023/03/03 19:39:12 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*syntax_creation(void *texture, char *name)
{
	int	height;
	int	width;

	texture = mlx_xpm_file_to_image(texture, name, &width, &height);
	if (!texture)
		exit(1);
	return (texture);
}

t_mlx	*creation_textures(t_mlx *ptr)
{
	ptr->player = syntax_creation(ptr->mlx, "textures/player.xpm");
	ptr->collect = syntax_creation(ptr->mlx, "textures/collect.xpm");
	ptr->space = syntax_creation(ptr->mlx, "textures/space.xpm");
	ptr->exit_0 = syntax_creation(ptr->mlx, "textures/exit_0.xpm");
	ptr->exit_1 = syntax_creation(ptr->mlx, "textures/exit_1.xpm");
	ptr->wall0_0 = syntax_creation(ptr->mlx, "textures/wall0_0.xpm");
	ptr->wall0_1 = syntax_creation(ptr->mlx, "textures/wall0_1.xpm");
	ptr->wall0_x = syntax_creation(ptr->mlx, "textures/wall0_x.xpm");
	ptr->wall1_0 = syntax_creation(ptr->mlx, "textures/wall1_0.xpm");
	ptr->wallin = syntax_creation(ptr->mlx, "textures/wall_inside.xpm");
	ptr->wall1_x = syntax_creation(ptr->mlx, "textures/wall1_x.xpm");
	ptr->wallx_0 = syntax_creation(ptr->mlx, "textures/wallx_0.xpm");
	ptr->wallx_1 = syntax_creation(ptr->mlx, "textures/wallx_1.xpm");
	ptr->wallx_x = syntax_creation(ptr->mlx, "textures/wallx_x.xpm");
	return (ptr);
}

void	full_wall(t_mlx *ptr, t_loopy index)
{
	int	x;
	int	y;

	x = index.j * 64;
	y = index.i * 64;
	if (index.i == 0 && index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_0, x, y);
	else if (index.i == 0 && index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_x, x, y);
	else if (index.i == ptr->size.x - 1 && index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_0, x, y);
	else if (index.i == ptr->size.x - 1 && index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_x, x, y);
	else if (index.i == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall0_1, x, y);
	else if (index.i == ptr->size.x - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallx_1, x, y);
	else if (index.j == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall1_0, x, y);
	else if (index.j == ptr->size.y - 1)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall1_x, x, y);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wallin, x, y);
}

t_mlx	display_all(t_mlx *ptr)
{
	t_loopy	index;

	ptr = creation_textures(ptr);
	index.i = 0;
	while (index.i < ptr->size.x)
	{
		index.j = 0;
		while (index.j < ptr->size.y)
		{
			if (ptr->area[index.i][index.j] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player, index.j
						* 64, index.i * 64);
			else if (ptr->area[index.i][index.j] == 'C')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect,
						index.j * 64, index.i * 64);
			else if (ptr->area[index.i][index.j] == '0')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->space, index.j
						* 64, index.i * 64);
			else if (ptr->area[index.i][index.j] == 'E')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit_0, index.j
						* 64, index.i * 64);
			else if (ptr->area[index.i][index.j] == '1')
				full_wall(ptr, index);
			index.j++;
		}
		index.i++;
	}
	*ptr = rev_search_p(*ptr);
	return (*ptr);
}

int	my_key_funct(int keycode, t_mlx *ptr)
{
	if (keycode == 13)
		move_w(ptr);
	else if (keycode == 0)
		move_a(ptr);
	else if (keycode == 1)
		move_s(ptr);
	else if (keycode == 2)
		move_d(ptr);
	*ptr = ft_loop(keycode, *ptr);
	return (0);
}
