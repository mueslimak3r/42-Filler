/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 06:01:57 by calamber          #+#    #+#             */
/*   Updated: 2019/04/09 06:01:59 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "fillerdefs.h"

int		getdata(t_data *data);
int		solve(t_data *data);
void	free_list(t_move **list);
void	get_moves(t_move **list, t_data *data);
void	mergesort_moves(t_move **list, t_data *data);
int		get_points(t_move *one, t_move *two, t_data *data);
int		checkifrepairsline(t_move *move, t_data *data);
int		checkheatvector(int xslope, int yslope, t_move *move, t_data *data);
int		checkforself(int xslope, int yslope, t_move *move, t_data *data);
int		checkbreakthrough(int xslope, int yslope, t_move *move, t_data *data);

#endif
