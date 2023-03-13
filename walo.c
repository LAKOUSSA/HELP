#include "so_long.h"

// void	wingame(t_mlx *ptr)
// {
// 	(void)ptr;
// 	// ptr->tasswera6 = mlx_xpm_file_to_image(ptr->mlx, "Win.xpm", &ptr->h,
// 	// 		&ptr->w);
// 	// ptr->wind = mlx_new_window(ptr->mlx, 1520, 640, "WINGAME");
// 	// mlx_put_image_to_window(ptr->mlx, ptr->wind, ptr->tasswera6, 0, 0);
// 	ft_printf("GAME OVER");
// 	// sleep(1);
// }

// void	ft_sleep(void)
// {
// 	int	i;

// 	i = 1000000000;
// 	while (i)
// 		i--;
// }

t_mlx	ft_loop(int keycode, t_mlx ptr)
{
	t_loopy	index;

	index.i = 0;
	while (index.i < ptr.size.x)
	{
		index.j = 0;
		while (index.j < ptr.size.y)
		{
			if (ptr.area[index.i][index.j] == 'P')
			{
				if ((keycode == 13 && ptr.area[ptr.p.px - 1][ptr.p.py] != '1')
					|| (keycode == 0 && ptr.area[ptr.p.px][ptr.p.py - 1] != '1')
					|| (keycode == 1 && ptr.area[ptr.p.px + 1][ptr.p.py] != '1')
					|| (keycode == 2 && ptr.area[ptr.p.px][ptr.p.py
						+ 1] != '1'))
					mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.player,
							index.j * 64, index.i * 64);
			}
			else if (ptr.area[index.i][index.j] == 'E')
				mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.exit_0, index.j
						* 64, index.i * 64);
			else if (ptr.area[index.i][index.j] == '0')
				mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.space, index.j
						* 64, index.i * 64);
			index.j++;
		}
		index.i++;
	}
	ptr = rev_search_e(ptr);
	if (!ptr.col)
		mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.exit_1, ptr.e.ey * 64,
				ptr.e.ex * 64);
	ptr = rev_search_p(ptr);
	return (ptr);
}
