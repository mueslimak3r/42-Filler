/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscmapchecks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 05:16:01 by calamber          #+#    #+#             */
/*   Updated: 2019/04/09 05:16:03 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		checkheatvector(int xslope, int yslope, t_move *move, t_data *data)
{
	int	x;
	int	y;

	x = move->x + data->piece.x_begin;
	y = move->y + data->piece.y_begin;
	while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
	{
		if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
			return (999);
		if (ft_checkifc((data->map.map)[y][x], data->o))
		{
			x = (x > move->x + data->piece.x_begin) ? x - (move->x +
				data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
			y = (y > move->y + data->piece.y_begin) ? y - (move->y +
				data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
			return (x + y);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (999);
}

int		checkforself(int xslope, int yslope, t_move *move, t_data *data)
{
	int	x;
	int	y;

	x = move->x + data->piece.x_begin;
	y = move->y + data->piece.y_begin;
	while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
	{
		if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
			return (0);
		if (ft_checkifc((data->map.map)[y][x], data->c))
		{
			x = (x > move->x + data->piece.x_begin) ? x - (move->x +
				data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
			y = (y > move->y + data->piece.y_begin) ? y - (move->y +
				data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
			return (x + y < 10 && x + y > 2 ? 1 : 0);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (0);
}

int		checkbreakthrough(int xslope, int yslope, t_move *move, t_data *data)
{
	int	x;
	int	y;

	x = move->x + data->piece.x_begin - xslope;
	y = move->y + data->piece.y_begin - yslope;
	while ((x += xslope) < data->map.x_size && x >= 0 &&
	(y += yslope) < data->map.y_size && y >= 0)
	{
		if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
			return (0);
		if (ft_checkifc((data->map.map)[y][x], data->o))
			while ((x += xslope) < data->map.x_size && x >= 0 &&
			(y += yslope) < data->map.y_size && y >= 0)
			{
				if (ft_checkifc((data->map.map)[y][x], data->c))
				{
					x = (x > move->x + data->piece.x_begin) ? x - (move->x +
					data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
					y = (y > move->y + data->piece.y_begin) ? y - (move->y +
					data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
					return (x + y < 5 && x + y > 0 ? 1 : 0);
				}
			}
	}
	return (0);
}
