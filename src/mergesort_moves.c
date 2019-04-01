#include "../includes/filler.h"

t_move		*sortedmerge_list(t_move *a, t_move *b)
{
	t_move	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (checkifswappable(&a, &b))
	{
		result = a;
		result->next = sortedmerge_list(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge_list(a, b->next);
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

void        mergesort_moves(t_move **list)
{
	t_move	*head;
	t_move	*a;
	t_move	*b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	fbsplit_list(head, &a, &b);
	mergesort_moves(&a);
	mergesort_moves(&b);
	*list = sortedmerge_list(a, b);
}