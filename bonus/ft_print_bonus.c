/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:54:11 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/29 16:05:58 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_bonus(t_data *params)
{
	char	*count;
	char	*star;
	char	*total_star;

	count = ft_itoa(params->count_move);
	star = ft_itoa(params->count_star);
	total_star = ft_itoa(params->total_star);
	mlx_string_put(params->mlx, params->win, 5, 11, 0xADD8E6, "TOTAL_MOVES : ");
	mlx_string_put(params->mlx, params->win, 6, 11, 0xADD8E6, "TOTAL_MOVES : ");
	mlx_string_put(params->mlx, params->win, 87, 12, 0xFDF5E6, count);
	mlx_string_put(params->mlx, params->win, 88, 12, 0xFDF5E6, count);
	free(count);
	mlx_string_put(params->mlx, params->win, 5, 25, 0xFFD700, "TOTAL_STARS : ");
	mlx_string_put(params->mlx, params->win, 6, 25, 0xFFD700, "TOTAL_STARS : ");
	mlx_string_put(params->mlx, params->win, 87, 26, 0xFDF5E6, star);
	mlx_string_put(params->mlx, params->win, 88, 26, 0xFDF5E6, star);
	free(star);
	mlx_string_put(params->mlx, params->win, 95, 27, 0xFFD700, "/");
	mlx_string_put(params->mlx, params->win, 96, 27, 0xFFD700, "/");
	mlx_string_put(params->mlx, params->win, 106, 27, 0xFDF5E6, total_star);
	mlx_string_put(params->mlx, params->win, 107, 27, 0xFDF5E6, total_star);
	free(total_star);
}
