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

int			checkheat(t_move *move, t_data *data)
{
	int		top;
	int		current;

	top = 99999;
	current = checkheatvector(1, 0, move, data);
	top = (current > top) ? current : top;
	current = checkheatvector(-1, 0, move, data);
	top = current < top ? current : top;
	current = checkheatvector(0, 1, move, data);
	top = current < top ? current : top;
	current = checkheatvector(0, -1, move, data);
	top = current < top ? current : top;
	current = checkheatvector(-1, -1, move, data);
	top = current < top ? current : top;
	current = checkheatvector(1, -1, move, data);
	top = current < top ? current : top;
	current = checkheatvector(-1, 1, move, data);
	top = current < top ? current : top;
	current = checkheatvector(1, 1, move, data);
	top = current < top ? current : top;
	top = (top == -1) ? 9999 : top;
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

	points = 0;
	if (checkifinside(one, data, 5, 1))
		points -= -50;
	if ((heata = checkheat(one, data)) < (checkheat(two, data)))
		points += 40;
	else if (heata == (checkheat(two, data)))
	{
		if (data->c == 'x' && one->y > two->y)
			points += 40;
		if (data->c == 'o' && one->y < two->y)
			points += 40;
	}
	if (checkifrepairsline(one, data) > 2)
		points += 15;
	if (canbreakthrough(one, data))
		points += 200;
	return (points);
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
