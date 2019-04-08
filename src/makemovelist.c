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

void		check_spot(t_move **list, t_data *data, int in_x, int in_y)
{
	int		can;
	int		x;
	int		y;
	int		bx;
	int		by;

	by = 0;
	can = 0;
	y = data->piece.y_begin - 1;
	while (y + 1 < data->piece.y_size && (data->piece.piece)[++y])
	{
		x = data->piece.x_begin - 1;
		bx = 0;
		while (++x < data->piece.x_size)
		{
			if ((data->piece.piece)[y][x] && (data->piece.piece)[y][x] == '*')
			{
				if (in_y + by >= data->map.y_size || in_x + bx >=
						data->map.x_size ||
						ft_checkifc((data->map.map)[in_y + by]
							[in_x + bx], data->o))
					return ;
				if (ft_checkifc((data->map.map)[in_y + by][in_x + bx], data->c))
					can++;
			}
			bx++;
		}
		by++;
	}
	if (can == 1)
		add_node(list, in_x - data->piece.x_begin, in_y - data->piece.y_begin);
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