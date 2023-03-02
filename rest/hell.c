/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:53:36 by gloukas           #+#    #+#             */
/*   Updated: 2023/03/02 16:15:40 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char *av[])
{
	struct s_mlx	ptr;

	ptr = ft_check_all(ac, av);
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, ptr.size.y * 64, ptr.size.x * 64,
			"so_long");
	ptr = display_all(&ptr);
	// mlx_hook(ptr.win, 2, 0, my_key_funct, &ptr);
	mlx_loop(ptr.mlx);
	// system("leaks so_long");
	return (0);
}
