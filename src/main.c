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

int     filler_loop(int playern, char c)
{
    t_data data;
    t_move *moves;

    moves = 0;
    clearstructs(&data);
    if (!(getdata(&data)))
        return(1);
    data.playern = playern;
    data.c = c;
    solve(&data);
    freeit(&data);
    return (1);
}

int         main(void)
{
    int     quit;
    char    *pinfo;
    int     playern;

    get_next_line(0, &pinfo);
    if (!pinfo[10] || (pinfo[10] != '1' && pinfo[10] != '2'))
		return (ft_error("error about player position"));
    playern = pinfo[10] - '0';
    quit = 0;
    while (!quit)
        quit = filler_loop(playern, (playern == 1) ? 'o' : 'x');
    return (0);
}