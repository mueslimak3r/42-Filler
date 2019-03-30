#include "../includes/filler.h"

void        check_spot(t_move **list, t_data *data, int in_x, int in_y)
{
    int     can;
    int     x;
    int     y;
    int     bx;
    int     by;

    by = 0;
    can = 0;
    if (list)
    {
        ;
    }
    y = data->piece.y_begin - 1;
    while ((data->piece.piece)[++y])
    {
        x = data->piece.x_begin -1;
        bx = 0;
        while (x < data->piece.x_size && (data->piece.piece)[++x])
        {
            if ((data->piece.piece)[y][x] == '*')
            {
                ft_printf("checking: x: %d y: %d | piece: x: %d y: %d\n", in_x + bx, in_y + by, x, y);
                if (!(data->map.map)[in_y + by][in_x + bx])
                    return ;
                if (ft_checkifc((data->map.map)[in_y + by][in_x + bx], data->c))
                    can++;
            }
            bx++;
        }
        by++;
    }
    if (can == 1)
        ft_printf("can: x: %d y: %d\n", in_x - data->piece.x_begin, in_y - data->piece.y_begin);
}

void        get_moves(t_move **list, t_data *data)
{
    int     y;
    int     x;

    y = -1;
    while ((data->map.map)[++y])
    {
        x = -1;
        while ((data->map.map)[y][++x])
            check_spot(list, data, x, y);
    }
}

void        solve(t_data *data)
{
    t_move  *list;

    list = 0;
    get_moves(&list, data);
    //order_moves(&list);
    //print_move(list);
    //free_list(&list);
}