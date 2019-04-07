#include "../includes/filler.h"

/*
int         checkheat(move)
{
    int     top;
    int     current;

    top = 0;
    current = 0;

    return (top);
}
*/

int         checkallsides(t_data *data, int x, int y)
{
    if (x + 2 < data->map.x_size && ft_checkifc(data->map.map[y][x + 1], data->c) && data->map.map[y][x + 2] == '.')
        return (1);
    else if (x - 2 >= 0 && ft_checkifc(data->map.map[y][x - 1], data->c) && data->map.map[y][x - 2] == '.')
        return (1);

    else if (y + 2 < data->map.y_size && ft_checkifc(data->map.map[y + 1][x], data->c) && data->map.map[y + 2][x] == '.')
        return (1);
    else if (y - 2 >= 0 && ft_checkifc(data->map.map[y - 1][x], data->c) && data->map.map[y - 2][x] == '.')
        return (1);

    else if (x + 2 < data->map.x_size && y + 2 < data->map.y_size && ft_checkifc(data->map.map[y + 1][x + 1], data->c) && data->map.map[y + 2][x + 2] == '.')
        return (1);
    else if (x - 2 >= 0 && y + 2 < data->map.y_size && ft_checkifc(data->map.map[y + 1][x - 1], data->c) && data->map.map[y + 2][x - 2] == '.')
        return (1);

    else if (x + 2 < data->map.x_size && y - 2 >= 0 && ft_checkifc(data->map.map[y - 1][x + 1], data->c) && data->map.map[y - 2][x + 2] == '.')
        return (1);
    else if (x - 2 >= 0 && y - 2 >= 0 && ft_checkifc(data->map.map[y - 1][x - 1], data->c) && data->map.map[y - 2][x - 2] == '.')
        return (1);
    return (0);
}

int         checkifrepairsline(t_move *move, t_data *data)
{
    int     can;
    int     x;
    int     y;
    int     bx;
    int     by;

    by = 0;
    can = 0;
    y = data->piece.y_begin - 1;
    while (y + 1 < data->piece.y_size && (data->piece.piece)[++y])
    {
        x = data->piece.x_begin -1;
        bx = 0;
        while (++x < data->piece.x_size)
        {
            if ((data->piece.piece)[y][x] && (data->piece.piece)[y][x] == '*')
            {
                if (move->y + by >= data->map.y_size || move->x + bx >= data->map.x_size)
                    return (0);
                if (checkallsides(data, move->y + by, move->x + bx))
                    can++;
            }
            bx++;
        }
        by++;
    }
    return (can);
}

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
    if (data)
        ;
    if ((a)->x < (b)->x)
        return (1);
    if ((a)->x == (b)->x && (a)->y < (b)->y)
        return (1);
/*
   if (get_points(a) > get_points(b))
        return (1);
*/
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