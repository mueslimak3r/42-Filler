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
    ft_memset(&(data->piece), 0, sizeof(t_map));
}

int     getmapsize(t_data *d)
{
    char *line;
    char *backup;
    line = 0;
    if ((get_next_line(0, &line)) < 0)
        return (0);
    backup = line;
    while(*line && !ft_isdigit(*line))
        line++;
    d->map.x_size = ft_atoi(line);
    d->map.y_size = ft_atoi(ft_strchr(line, ' '));
    ft_strdel(&backup);
    return (1);
}

int     makemap(t_data *data)
{
    char    *line;
    int     y;

    line = 0;
    y = 0;
    if (!(data->map.map = ft_memalloc(sizeof(char*) *
                        (data->map.y_size + 1))))
        return (0);
    if ((get_next_line(0, &line)) < 0)
        return (0);
    ft_strdel(&line);
    while (get_next_line(0, &line) > 0)
    {
        (data->map.map)[y] = ft_strdup(line + 4);
        ft_printf("y: %d | %s\n", y, (data->map.map)[y]);
        ft_strdel(&line);
        y++;
    }
    return (1);
}

int     getdata(t_data *data)
{
    if (!(getmapsize(data)))
        return (print_return("error getting map\n", 0, 2));
    if (!(makemap(data)))
        return (print_return("error making map\n", 0, 2));
    return (1);
}

void    freeit(t_data *data)
{
    if (data)
        ;
    //ft_arraydel(data->map.map);
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
    while (1)
        ;
    return (0);
}