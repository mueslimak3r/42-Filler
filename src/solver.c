#include "../includes/filler.h"

int         checkifswappable(t_move **a, t_move **b)
{
    if ((*a)->x < (*b)->x)
        return (1);
    if ((*a)->x == (*b)->x && (*a)->y < (*b)->y)
        return (1);
    return (0);
}

int         solve(t_data *data)
{
    t_move  *list;

    list = 0;
    get_moves(&list, data);
    //printlist(list);
    if (list)
    {
        mergesort_moves(&list);
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