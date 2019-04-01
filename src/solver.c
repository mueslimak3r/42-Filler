#include "../includes/filler.h"

int         checkifswappable(t_move **a, t_move **b)
{
    if ((*a)->x < (*b)->x)
        return (1);
    if ((*a)->x == (*b)->x && (*a)->y < (*b)->y)
        return (1);
    return (0);
}

void        solve(t_data *data)
{
    t_move  *list;

    list = 0;
    get_moves(&list, data);
    mergesort_moves(&list);
    //printlist(list);
    if (list)
        ft_printf("%d %d\n", list->x, list->y);
    else
        ft_printf("%d %d\n", 0, 0);
    free_list(&list);
}