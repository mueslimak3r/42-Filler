#include "../includes/filler.h"
/*
int         checkheat(t_move *move, t_data *data)
{
    int     top;
    int     current;

    top = 0;
    current = 0;

    return (top);
}
*/
int         getpoints(t_move *move, t_data *data)
{
    int     points;

    points = 0;
    //points += checkheat(move, data);
    points += checkifrepairsline(move, data);
    return (points);
}

int         checkifswappable(t_move *a, t_move *b, t_data *data)
{
    /*
    if (data)
    {
        ;
    }
    if ((a)->x < (b)->x)
        return (1);
    if ((a)->x == (b)->x && (a)->y < (b)->y)
        return (1);
    */

   if (getpoints(a, data) > getpoints(b, data))
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