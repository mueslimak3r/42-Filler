/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemovelist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:30:14 by calamber          #+#    #+#             */
/*   Updated: 2019/04/07 23:34:06 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		add_node(t_move **list, int x, int y)
{
	t_move	*new;

	if (!(new = ft_memalloc(sizeof(t_move))))
		return ;
	new->x = x;
	new->y = y;
	new->next = *list;
	*list = new;
}

void		check_spot(t_move **list, t_data *d, int nx, int ny)
{
	int		can;
	int		x;
	int		y;
	int		bx;
	int		by;

	by = -1;
	can = 0;
	y = d->piece.y_begin - 1;
	while (y + 1 < d->piece.y_size && (d->piece.piece)[++y] && ++by > -1)
	{
		x = d->piece.x_begin - 1;
		bx = -1;
		while (++x < d->piece.x_size && ++bx > -1)
			if ((d->piece.piece)[y][x] && (d->piece.piece)[y][x] == '*')
			{
				if (ny + by >= d->map.y_size || nx + bx >= d->map.x_size
				|| ft_checkifc((d->map.map)[ny + by][nx + bx], d->o))
					return ;
				if (ft_checkifc((d->map.map)[ny + by][nx + bx], d->c))
					can++;
			}
	}
	(can == 1) ? add_node(list, nx -
	d->piece.x_begin, ny - d->piece.y_begin) : 0;
}

void		get_moves(t_move **list, t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (y + 1 < data->map.y_size && (data->map.map)[++y])
	{
		x = -1;
		while (x + 1 < data->map.x_size && (data->map.map)[y][++x])
			check_spot(list, data, x, y);
	}
}

void		free_list(t_move **list)
{
	t_move	*temp;

	while (*list)
	{
		temp = *list;
		*list = (*list)->next;
		temp->next = 0;
		free(temp);
	}
}
