/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:00:00 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/16 15:00:00 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render_tile(t_data *params, int x, int y, char tile)
{
	void	*img;

	if (tile == '1')
		img = params->wall;
	else if (tile == '0')
		img = params->empty;
	else if (tile == 'P')
		img = params->player;
	else if (tile == 'C')
		img = params->object;
	else if (tile == 'E')
		img = params->exit;
	else
		return ;
	mlx_put_image_to_window(params->mlx, params->win, img, x * TS, y * TS);
	ft_print_bonus(params);
}

void	load_images(t_data *params)
{
	int	width;
	int	height;

	params->wall = mlx_xpm_file_to_image(params->mlx, "img/wall.xpm", &width,
			&height);
	params->empty = mlx_xpm_file_to_image(params->mlx, "img/floor.xpm", &width,
			&height);
	params->object = mlx_xpm_file_to_image(params->mlx, "img/star.xpm", &width,
			&height);
	params->player = mlx_xpm_file_to_image(params->mlx, "img/player.xpm",
			&width, &height);
	params->exit = mlx_xpm_file_to_image(params->mlx, "img/exit.xpm", &width,
			&height);
	if (!params->wall || !params->empty || !params->object || !params->player
		|| !params->exit)
	{
		ft_printf("Error\nFailed to load images\n");
		exit_map(params);
	}
}

void	render_map(t_data *params, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			render_tile(params, x, y, map[y][x]);
			x++;
		}
		y++;
	}
}

void	init_window(t_data *params, char **argv)
{
	params->mlx = mlx_init();
	if (!params->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		ft_free_map(params->map);
		exit(1);
	}
	params->win = mlx_new_window(params->mlx, (ft_strlen(params->map[0]) * 32),
			(ft_count_line(argv) * 32), "So_Long");
	if (!params->win)
	{
		ft_printf("Error\nFailed to create window\n");
		free(params->mlx);
		ft_free_map(params->map);
		exit(1);
	}
}
