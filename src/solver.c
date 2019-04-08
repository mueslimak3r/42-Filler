#include "../includes/filler.h"

int         checkvector(int xslope, int yslope, t_move *move, t_data *data)
{
    int     x;
    int     y;

    x = move->x + data->piece.x_begin;
    y = move->y + data->piece.y_begin;
    while (x < data->map.x_size && x >= 0 && y < data->map.y_size && y >= 0)
    {
        if (x >= data->map.x_size || y >= data->map.y_size || y < 0 || x < 0)
            return (0);
        //ft_printf("ybegin: %d xbegin: %d\n", data->piece.y_begin, data->piece.x_begin);
        //ft_printf("checking: move: y: %d x: %d |spot: y: %d x: %d | slope: y: %d x: %d\n", move->y, move->x, y, x, yslope, xslope);
        if (ft_checkifc((data->map.map)[y][x], data->o))
        {
            return (x - move->x + data->piece.x_begin + y - move->y + data->piece.y_begin);
        }
        if (xslope != 0)
            x += xslope;
        if (yslope != 0)
            y += yslope;
    }
    return (0);
}

int         checkheat(t_move *move, t_data *data)
{
    int     top;

    top = 0;
    top = checkvector(1, 0, move, data) > top ? checkvector(1, 0, move, data) : top;
    top = checkvector(-1, 0, move, data) > top ? checkvector(-1, 0, move, data) : top;
    top = checkvector(0, 1, move, data) > top ? checkvector(0, 1, move, data) : top;
    top = checkvector(0, -1, move, data) > top ? checkvector(0, -1, move, data) : top;
    top = checkvector(-1, -1, move, data) > top ? checkvector(-1, -1, move, data) : top;
    top = checkvector(1, -1, move, data) > top ? checkvector(1, -1, move, data) : top;
    top = checkvector(-1, 1, move, data) > top ? checkvector(-1, 1, move, data) : top;
    top = checkvector(1, 1, move, data) > top ? checkvector(1, 1, move, data) : top;
    return (top);
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
    //if (heat(a) < heat(b) && checkifrepairsline(a, data))
    //        return (1);
    if (checkheat(a, data) > checkheat(b, data))
    {
        return (1);
    }
    else if (checkheat(a, data) < checkheat(b, data))
    {
        if (checkifrepairsline(a, data) > 2)
            return (1);
    }
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