#include "../includes/filler.h"

int     print_return(char *note, int ret, int fd)
{
    ft_putstr_fd(note, fd);
    return (ret);
}

void    clearstructs(t_data *data)
{
    ft_memset(data, 0, sizeof(t_data));
    ft_memset(&(data->map), 0, sizeof(t_map));
    ft_memset(&(data->piece), 0, sizeof(t_piece));
    data->piece.x_begin = -1;
    data->piece.y_begin = -1;
}

int     getdata(t_data *data)
{
    if (!(getgridsize(&(data->map.y_size), &(data->map.x_size))))
        return (print_return("error getting map size\n", 0, 2));
    if (!(makemap(data)))
        return (print_return("error making map\n", 0, 2));
    if (!(getgridsize(&(data->piece.y_size), &(data->piece.x_size))))
        return (print_return("error getting piece size\n", 0, 2));
    if (!(makepiece(data)))
        return (print_return("error making piece\n", 0, 2));
    return (1);
}

void    freeit(t_data *data)
{
    ft_arraydel(data->map.map);
    ft_arraydel(data->piece.piece);
}

int     filler_loop(void)
{
    t_data data;
    t_move *moves;

    moves = 0;
    clearstructs(&data);
    if (!(getdata(&data)))
        return(1);
    freeit(&data);
    //findmoves(&moves);
    //printmove(moves);
    return (1);
}

int     main(void)
{
    int quit;

    quit = 0;
    while (!quit)
        quit = filler_loop();
    return (0);
}