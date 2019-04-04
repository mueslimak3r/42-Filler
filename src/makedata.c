#include "../includes/filler.h"

int     getgridsize(int *y, int *x)
{
    char *line;
    char *backup;
    line = 0;
    if ((get_next_line(0, &line)) < 0)
        return (0);
    backup = line;
    if (line && ft_strlen(line) > 0)
    {
        //ft_printf("line: %s\n", line);
        while(*line && !ft_isdigit(*line))
            line++;
        if (!(*line))
            return (0);
        *y = ft_atoi(line);
        if (!(*(ft_strchr(line, ' '))))
            return (0);
        *x = ft_atoi(ft_strchr(line, ' '));
        if (!(*x) || !(*y))
            return (0);
        ft_strdel(&backup);
        return (1);
    }
    ft_strdel(&backup);
    return (0);
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
    //ft_printf("piece to place:\n");
    while (y < data->piece.y_size && get_next_line(0, &line) > 0)
    {
        if ((int)ft_strlen(line) != data->piece.x_size)
            return (0);
        (data->piece.piece)[y] = ft_strdup(line);
        //ft_printf("y: %-4d | %s\n", y, (data->piece.piece)[y]);
        data->piece.y_begin = (ft_strchr(line, '*') >= line && (y < data->piece.y_begin || data->piece.y_begin == -1)) ?
                                y : data->piece.y_begin;
        data->piece.x_begin = (ft_strchr(line, '*') >= line && ((ft_strchr(line, '*') - line) < data->piece.x_begin || data->piece.x_begin == -1)) ?
                                (ft_strchr(line, '*') - line) : data->piece.x_begin;
        y++;
        ft_strdel(&line);
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
    //ft_printf("size: x: %d y: %d\n", data->map.x_size, data->map.y_size);
    if ((get_next_line(0, &line)) < 0)
        return (0);
    ft_strdel(&line);
    while (y < data->map.y_size && get_next_line(0, &line) > 0)
    {
        (data->map.map)[y] = ft_strdup(line + 4);
        if ((int)ft_strlen(data->map.map[y]) != data->map.x_size)
            return (0);
        ft_strdel(&line);
        y++;
    }
    return (1);
}

int     getdata(t_data *data)
{
    if ((getgridsize(&(data->map.y_size), &(data->map.x_size))) != 1)
        return (-1);
    if (!(makemap(data)))
        return (-1);
    if (!(getgridsize(&(data->piece.y_size), &(data->piece.x_size))))
        return (-1);
    if (!(makepiece(data)))
        return (-1);
    return (1);
}
