/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:27:18 by calamber          #+#    #+#             */
/*   Updated: 2019/04/07 23:29:54 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			checkheatvector(int xslope, int yslope, t_move *move, t_data *data)
{
	int		x;
	int		y;

	x = move->x + data->piece.x_begin;
	y = move->y + data->piece.y_begin;
	while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
	{
		if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
			return (0);
		if (ft_checkifc((data->map.map)[y][x], data->o))
		{
			x = (x > move->x + data->piece.x_begin) ? x - (move->x + data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
			y = (y > move->y + data->piece.y_begin) ? y - (move->y + data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
			return (x + y);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (0);
}

int			checkforself(int xslope, int yslope, t_move *move, t_data *data)
{
	int		x;
	int		y;

	x = move->x + data->piece.x_begin;
	y = move->y + data->piece.y_begin;
	while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
	{
		if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
			return (0);
		if (ft_checkifc((data->map.map)[y][x], data->c))
		{
			x = (x > move->x + data->piece.x_begin) ? x - (move->x + data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
			y = (y > move->y + data->piece.y_begin) ? y - (move->y + data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
			return (x + y > 15 ? 0 : 1);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (0);
}

int			checkheat(t_move *move, t_data *data)
{
	int		top;
	int		current;

	top = -1;
	top = (current = checkheatvector(1, 0, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(-1, 0, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(0, 1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(0, -1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(-1, -1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(1, -1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(-1, 1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (current = checkheatvector(1, 1, move, data) < top || top == -1) && current >= 2 ? current : top;
	top = (top == -1) ? 9999 : top;
	return (top);
}

int			checkifinside(t_move *move, t_data *data)
{
	int		top;

	top = 0;
	top += checkforself(1, 0, move, data);
	top += checkforself(-1, 0, move, data);
	top += checkforself(0, 1, move, data);

	top += checkforself(0, -1, move, data);
	top += checkforself(-1, -1, move, data);
	top += checkforself(1, -1, move, data);
	top += checkforself(-1, 1, move, data);
	top += checkforself(1, 1, move, data);
	if (top > 5)
		return (1);
	return (0);
}

int			get_points(t_move *one, t_move *two, t_data *data)
{
	int		points;

	points = 0;
	if (one || two || data)
		;
	if (checkheat(one, data) <= 25)
		points += (checkheat(one, data) <= 10) ? 6 : 4;
	if (checkifinside(one, data))
		points -= 5;
	if (checkheat(one, data) < checkheat(two, data))
		points += 5;
	if (checkifrepairsline(one, data))
		points += 1;
	return (points);
}

int			checkorder(t_move *a, t_move *b, t_data *data)
{
	if (get_points(a, b, data) > get_points(b, a, data))
		return (1);
	return (0);
}

int			solve(t_data *data)
{
	t_move	*list;

	list = 0;
	get_moves(&list, data);
	if (list)
	{
		mergesort_moves(&list, data);
		ft_putnbr(list->y);
		ft_putchar(' ');
		ft_putnbr(list->x);
		ft_putchar('\n');
		free_list(&list);
		return (1);
	}
	else
		ft_putstr("0 0\n");
	return (-1);
}
