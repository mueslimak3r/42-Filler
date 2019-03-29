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
    if (!(data->map.map = ft_memalloc(sizeof(char) *
                        (data->map.y_size + 1))))
        return (0);
    if ((get_next_line(0, &line)) < 0)
        return (0);
    ft_strdel(&line);
    while (get_next_line(0, &line) > 0)
    {
        if (ft_strlen(line) > 4)
            (data->map.map)[y] = ft_strdup(line + 4);
        //ft_strdel(&line);
        ft_printf("%s\n", (data->map.map)[y]);
        y++;
    }
    return (0);
}

int     getdata(t_data *data)
{
    if (!(getmapsize(data)))
        return (1);
    if (!(makemap(data)))
        return (1);
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
        return(print_return("error getting map and piece", 0, 2));
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