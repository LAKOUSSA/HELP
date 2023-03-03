/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloukas <gloukas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:34:01 by gloukas           #+#    #+#             */
/*   Updated: 2023/03/03 19:37:39 by gloukas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_w(t_mlx *ptr)
{
	if (ptr->area[ptr->p.px - 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
		- 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px - 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
	}
	else if (ptr->area[ptr->p.px - 1][ptr->p.py] == 'E' && !ptr->col)
	{
		ft_printf("GAME OVER");
		exit(1);
	}
}

void	move_a(t_mlx *ptr)
{
	if (ptr->area[ptr->p.px][ptr->p.py - 1] == '0'
		|| ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py - 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
	}
	else if (ptr->area[ptr->p.px][ptr->p.py - 1] == 'E' && !ptr->col)
	{
		ft_printf("GAME OVER");
		exit(1);
	}
}

void	move_s(t_mlx *ptr)
{
	if (ptr->area[ptr->p.px + 1][ptr->p.py] == '0' || ptr->area[ptr->p.px
		+ 1][ptr->p.py] == 'C')
	{
		if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px + 1][ptr->p.py] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
	}
	else if (ptr->area[ptr->p.px + 1][ptr->p.py] == 'E' && !ptr->col)
	{
		ft_printf("GAME OVER");
		exit(1);
	}
}

void	move_d(t_mlx *ptr)
{
	if (ptr->area[ptr->p.px][ptr->p.py + 1] == '0'
		|| ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
	{
		if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'C')
			ptr->col--;
		ptr->area[ptr->p.px][ptr->p.py + 1] = 'P';
		ptr->area[ptr->p.px][ptr->p.py] = '0';
	}
	else if (ptr->area[ptr->p.px][ptr->p.py + 1] == 'E' && !ptr->col)
	{
		ft_printf("GAME OVER");
		exit(1);
	}
}
