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

void    freeit(t_data *data)
{
    ft_arraydel(data->map.map);
    ft_arraydel(data->piece.piece);
}

void    printit(char **c)
{
    int size;
    int i = 0;
    int b;
    int y;
    y = -1;
    size = ft_strlen(*c);
    ft_printf("map to fill:\n    ");
    while(i < size)
    {
        b = -1;
        while (i < size && ++b < 10)
        {
            ft_printf("%d", b);
            i++;
        }
    }
    ft_printf("\n");
    while (c[++y])
    {
        ft_printf("%3d %s\n", y, c[y]);
    }
    i = 0;
    ft_printf("    ");
    while(i < size)
    {
        b = -1;
        while (i < size && ++b < 10)
        {
            ft_printf("%d", b);
            i++;
        }
    }
    ft_printf("\n");
}

int     filler_loop(int playern, char c)
{
    t_data data;
    int     ret;

    clearstructs(&data);
    if ((ret = getdata(&data)) < 1)
        return(ret);
    data.playern = playern;
    data.c = c;
    //printit(data.map.map);
    solve(&data);
    freeit(&data);
    return (0);
}

int         main(void)
{
    int     quit;
    char    *pinfo;
    int     playern;

    pinfo = 0;
    get_next_line(0, &pinfo);
    if (!pinfo[10] || (pinfo[10] != '1' && pinfo[10] != '2'))
    {
        ft_strdel(&pinfo);
		return (print_return("error about player position", 0, 2));
    }
    playern = pinfo[10] - '0';
    ft_strdel(&pinfo);
    quit = 0;
    while (quit != -1)
        quit = filler_loop(playern, (playern == 1) ? 'o' : 'x');
    return (0);
}