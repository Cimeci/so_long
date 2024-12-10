/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:18:20 by inowak--          #+#    #+#             */
/*   Updated: 2024/12/03 08:02:03 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		ft_printf("Error\nFirst or last caracter is invalid\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
		{
			ft_printf("Error\nInvalid characters in map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_start_last(char **map, char **argv)
{
	int	i;
	int	last;

	last = ft_count_line(argv);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[last - 1][i])
	{
		if (map[last - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_len(char **map)
{
	size_t	original_len;
	int		j;

	j = 1;
	original_len = ft_strlen(map[0]);
	while (map[j])
	{
		if (ft_strlen(map[j]) != original_len)
			return (0);
		j++;
	}
	return (1);
}

static int	ft_check_map_extension(char **map, char **argv)
{
	if (ft_check_len(map) == 0)
	{
		ft_printf("Error\nInconsistent line length\n");
		return (0);
	}
	if (ft_strlen(map[0]) + 1 > 60 || ft_count_line(argv) > 30)
	{
		ft_printf("Error\nMap size exceeds limit\n");
		return (0);
	}
	if (ft_check_start_last(map, argv) == 0)
	{
		ft_printf("Error\nFirst or last line is invalid\n");
		return (0);
	}
	return (1);
}

char	**ft_check_map(char **map, char **argv)
{
	int	j;
	int	total_lines;

	total_lines = ft_count_line(argv);
	j = 1;
	if (ft_check_map_extension(map, argv) == 0)
		return (ft_free_map(map));
	while (map[j] && j < total_lines)
	{
		if (!ft_check_line(map[j]))
			return (ft_free_map(map));
		j++;
	}
	return (map);
}