/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:25 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/03 08:04:05 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cleanup(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->empty)
		mlx_destroy_image(data->mlx, data->empty);
	if (data->object)
		mlx_destroy_image(data->mlx, data->object);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_map(data->map);
}

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nFailed to read file (fd error)\n");
		exit(0);
	}
}

void	ft_error_map_init(void)
{
	ft_printf("Error\nMap ends with an empty line\n");
	exit(0);
}
