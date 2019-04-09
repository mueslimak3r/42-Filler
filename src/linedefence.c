/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedefence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:40:17 by calamber          #+#    #+#             */
/*   Updated: 2019/04/07 23:45:33 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			checkallsides(t_data *data, int x, int y)
{
	int		ret;

	ret = 0;
	if (x >= data->map.x_size || y >= data->map.y_size)
		return (0);
	ret += (x + 2 < data->map.x_size && ft_checkifc(data->map.map[y][x + 1]
				, data->c) && data->map.map[y][x + 2] == '.') ? 1 : 0;
	ret += (x - 2 >= 0 && ft_checkifc(data->map.map[y][x - 1],
				data->c) && data->map.map[y][x - 2] == '.') ? 1 : 0;
	ret += (y + 2 < data->map.y_size && ft_checkifc(data->map.map[y + 1][x],
				data->c) && data->map.map[y + 2][x] == '.') ? 1 : 0;
	ret += (y - 2 >= 0 && ft_checkifc(data->map.map[y - 1][x], data->c) &&
			data->map.map[y - 2][x] == '.') ? 1 : 0;
	ret += (x + 2 < data->map.x_size && y + 2 < data->map.y_size &&
			ft_checkifc(data->map.map[y + 1][x + 1], data->c) &&
				data->map.map[y + 2][x + 2] == '.') ? 1 : 0;
	ret += (x - 2 >= 0 && y + 2 < data->map.y_size &&
			ft_checkifc(data->map.map[y + 1][x - 1], data->c) &&
				data->map.map[y + 2][x - 2] == '.') ? 1 : 0;
	ret += (x + 2 < data->map.x_size && y - 2 >= 0 &&
			ft_checkifc(data->map.map[y - 1][x + 1], data->c) &&
				data->map.map[y - 2][x + 2] == '.') ? 1 : 0;
	ret += (x - 2 >= 0 && y - 2 >= 0 && ft_checkifc(data->map.map[y - 1][x - 1]
	, data->c) && data->map.map[y - 2][x - 2] == '.') ? 1 : 0;
	return (ret > 0 ? 1 : 0);
}

int			checkifrepairsline(t_move *move, t_data *data)
{
	int		can;
	int		x;
	int		y;
	int		bx;
	int		by;

	by = -1;
	can = 0;
	y = data->piece.y_begin - 1;
	while (y + 1 < data->piece.y_size && (data->piece.piece)[++y] && ++by > -1)
	{
		x = data->piece.x_begin - 1;
		bx = 0;
		while (++x < data->piece.x_size && ++bx > -1)
			if ((data->piece.piece)[y][x] && (data->piece.piece)[y][x] == '*')
			{
				if (move->y + data->piece.y_begin + by >= data->map.y_size ||
				move->x + data->piece.x_begin + bx >= data->map.x_size)
					return (0);
				if (checkallsides(data, move->y + data->piece.y_begin + by,
				move->x + data->piece.x_begin + bx))
					can++;
			}
	}
	return (can);
}
