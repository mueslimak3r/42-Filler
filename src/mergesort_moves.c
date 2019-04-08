/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 23:26:38 by calamber          #+#    #+#             */
/*   Updated: 2019/04/07 23:26:58 by calamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_move		*sortedmerge_list(t_move *a, t_move *b, t_data *data)
{
	t_move	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (checkorder(a, b, data))
	{
		result = a;
		result->next = sortedmerge_list(a->next, b, data);
	}
	else
	{
		result = b;
		result->next = sortedmerge_list(a, b->next, data);
	}
	return (result);
}

void		fbsplit_list(t_move *source, t_move **frontref, t_move **backref)
{
	t_move	*fast;
	t_move	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

void		mergesort_moves(t_move **list, t_data *data)
{
	t_move	*head;
	t_move	*a;
	t_move	*b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	fbsplit_list(head, &a, &b);
	mergesort_moves(&a, data);
	mergesort_moves(&b, data);
	*list = sortedmerge_list(a, b, data);
}
