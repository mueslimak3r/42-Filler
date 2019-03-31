#include "../includes/filler.h"

void        add_node(t_move **list, int x, int y)
{
    t_move  *new;

    if (!(new = ft_memalloc(sizeof(t_move))))
        return ;
    new->x = x;
    new->y = y;
    new->next = *list;
    *list = new;
}

void        check_spot(t_move **list, t_data *data, int in_x, int in_y)
{
    int     can;
    int     x;
    int     y;
    int     bx;
    int     by;

    by = 0;
    can = 0;
    y = data->piece.y_begin - 1;
    while ((data->piece.piece)[++y])
    {
        x = data->piece.x_begin -1;
        bx = 0;
        while (x < data->piece.x_size && (data->piece.piece)[++x])
        {
            if ((data->piece.piece)[y][x] == '*')
            {
                
                if (in_y + by >= data->map.y_size || in_x + bx >= data->map.x_size || !(data->map.map)[in_y + by][in_x + bx])
                    return ;
                if (ft_checkifc((data->map.map)[in_y + by][in_x + bx], data->c))
                    can++;
            }
            bx++;
        }
        by++;
    }
    if (can == 1)
        add_node(list, in_x - data->piece.x_begin, in_y - data->piece.y_begin);
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
    while (list)
    {
        ft_printf("x: %d y: %d\n", list->x, list->y);
        list = list->next;
    }
    //order_moves(&list);
    //print_move(list);
    //free_list(&list);
}