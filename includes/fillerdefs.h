/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillerdefs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 05:56:53 by calamber          #+#    #+#             */
/*   Updated: 2019/04/09 06:00:23 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLERDEFS_H
# define FILLERDEFS_H

typedef struct		s_map
{
	int				x_size;
	int				y_size;
	char			**map;
}					t_map;

typedef struct		s_piece
{
	int				x_size;
	int				y_size;
	int				x_begin;
	int				y_begin;
	char			**piece;
}					t_piece;

typedef struct		s_data
{
	t_map			map;
	t_piece			piece;
	int				playern;
	char			c;
	char			o;
}					t_data;

typedef struct		s_move
{
	int				x;
	int				y;
	struct s_move	*next;
}					t_move;

#endif
