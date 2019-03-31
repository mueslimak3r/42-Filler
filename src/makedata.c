#include "../includes/filler.h"

int     getgridsize(int *y, int *x)
{
    char *line;
    char *backup;
    line = 0;
    if ((get_next_line(0, &line)) < 0)
        return (0);
    backup = line;
    while(*line && !ft_isdigit(*line))
        line++;
    *y = ft_atoi(line);
    *x = ft_atoi(ft_strchr(line, ' '));
    ft_strdel(&backup);
    return (1);
}

int     makepiece(t_data *data)
{
    char    *line;
    int     y;

    line = 0;
    y = 0;
    if (!(data->piece.piece = ft_memalloc(sizeof(char*) *
                        (data->piece.y_size + 1))))
        return (0);

    while (get_next_line(0, &line) > 0)
    {
        (data->piece.piece)[y] = line;
        ft_printf("y: %-4d | %s\n", y, (data->piece.piece)[y]);
        data->piece.y_begin = (ft_strchr(line, '*') >= line && (y < data->piece.y_begin || data->piece.y_begin == -1)) ?
                                y : data->piece.y_begin;
        data->piece.x_begin = (ft_strchr(line, '*') >= line && ((ft_strchr(line, '*') - line) < data->piece.x_begin || data->piece.x_begin == -1)) ?
                                (ft_strchr(line, '*') - line) : data->piece.x_begin;
        y++;
    }
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
    ft_printf("size: x: %d y: %d\n", data->map.x_size, data->map.y_size);
    if ((get_next_line(0, &line)) < 0)
        return (0);
    ft_strdel(&line);
    while (y < data->map.y_size && get_next_line(0, &line) > 0)
    {
        (data->map.map)[y] = ft_strdup(line + 4);
        ft_strdel(&line);
        y++;
    }
    return (1);
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
