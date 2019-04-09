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
			return (999);
		if (ft_checkifc((data->map.map)[y][x], data->o))
		{
			//ft_printf("found! y: %d x: %d", y, x);
			x = (x > move->x + data->piece.x_begin) ? x - (move->x + data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
			y = (y > move->y + data->piece.y_begin) ? y - (move->y + data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
			//ft_printf("diff: %d\n", x + y);
			return (x + y);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (999);
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
			return (x + y < 10 && x + y > 2 ? 1 : 0);
		}
		if (xslope != 0)
			x += xslope;
		if (yslope != 0)
			y += yslope;
	}
	return (0);
}

int			checkbreakthrough(int xslope, int yslope, t_move *move, t_data *data)
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
			while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
			{
				if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
					return (0);
				if (ft_checkifc((data->map.map)[y][x], data->c))
				{
					x = (x > move->x + data->piece.x_begin) ? x - (move->x + data->piece.x_begin) : (move->x + data->piece.x_begin) - x;
					y = (y > move->y + data->piece.y_begin) ? y - (move->y + data->piece.y_begin) : (move->y + data->piece.y_begin) - y;
					return (x + y < 5 && x + y > 0 ? 1 : 0);
				}
				if (xslope != 0)
					x += xslope;
				if (yslope != 0)
					y += yslope;
			}
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

	top = 99999;
	top = (current = checkheatvector(1, 0, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(-1, 0, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(0, 1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(0, -1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(-1, -1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(1, -1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(-1, 1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (current = checkheatvector(1, 1, move, data)) < top /*&& current >= 2*/ ? current : top;
	top = (top == -1) ? 9999 : top;
	//ft_printf("lowest diff: %d\n", top);
	return (top);
}

int			checkifinside(t_move *move, t_data *data, int weight, int sign)
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
	if (sign == 1 && top > weight)
		return (1);
	else if (sign == 0 && top < weight)
		return (1);
	return (0);
}

int			canbreakthrough(t_move *move, t_data *data)
{
	int		can;

	can = 0;
	can += checkbreakthrough(1, 0, move, data);
	can += checkbreakthrough(-1, 0, move, data);
	can += checkbreakthrough(0, 1, move, data);

	can += checkbreakthrough(0, -1, move, data);
	can += checkbreakthrough(-1, -1, move, data);
	can += checkbreakthrough(1, -1, move, data);
	can += checkbreakthrough(-1, 1, move, data);
	can += checkbreakthrough(1, 1, move, data);
	return (can > 0 ? 1 : 0);
}

int			get_points(t_move *one, t_move *two, t_data *data)
{
	int		points;
	int		heata;
	int		heatb;

	points = 0;
	if (checkifinside(one, data, 5, 1))
	{
		points -= -50;
		//ft_printf("minus 30 for being inside\n");
	}
	if ((heata = checkheat(one, data)) < (heatb = checkheat(two, data)))
	{
		//ft_printf("plus 10, closer to enemy than move: y: %d x: %d\n", two->y, two->x);
		points += 40;
	}
	else if (heata == heatb)
	{
		if (data->c == 'x' && one->y > two->y)
			points += 40;
		if (data->c == 'o' && one->y < two->y)
			points += 40;
	}
	if (checkifrepairsline(one, data) > 2)
	{
		//ft_printf("plus 5 for repairs\n");
		points += 15;
	}
	if (canbreakthrough(one, data))
	{
		//ft_printf("plus 200 for sneaky break through\n");
		points += 200;
	}
	//ft_printf("%d total\n\n", points);
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
