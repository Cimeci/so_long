/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:29:00 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/03 07:56:20 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_map_extension(char *argv)
{
	int		i;
	int		j;
	int		k;
	char	*name_extension;

	i = ft_strlen(argv) - 4;
	j = 0;
	k = 0;
	name_extension = ".ber";
	while (argv[i] == name_extension[k])
	{
		if (name_extension[k + 1] == '\0')
			return (1);
		k++;
		i++;
	}
	return (0);
}

static void	ft_initialisation(t_data *params)
{
	params->count_move = 0;
	params->count_star = 0;
	params->total_star = ft_count_char(params->map, 'C');
	params->exit_position = ft_locate(params->map, 'E');
}

int	main(int argc, char **argv)
{
	t_data	params;

	if (argc != 2 || !ft_check_map_extension(argv[1]))
	{
		ft_printf("Error\nMap file is false or missing.\n");
		return (0);
	}
	if (main_extension(argv) == 0)
		return (0);
	params.map = ft_map(argv);
	if (!params.map)
	{
		ft_printf("Error\nMap is invalid.\n");
		return (0);
	}
	ft_initialisation(&params);
	init_window(&params, argv);
	load_images(&params);
	render_map(&params, params.map);
	mlx_key_hook(params.win, key_press, &params);
	mlx_hook(params.win, 17, 0L, exit_hook, &params);
	mlx_loop(params.mlx);
	ft_free_map(params.map);
	cleanup(&params);
	return (0);
}
