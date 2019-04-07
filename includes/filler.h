#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct  s_map
{
    int         x_size;
    int         y_size;
    char        **map;
}               t_map;

typedef struct  s_piece
{
    int         x_size;
    int         y_size;
    int         x_begin;
    int         y_begin;
    char        **piece;
}               t_piece;

typedef struct  s_data
{
    t_map       map;
    t_piece     piece;
    int         playern;
    char        c;
    char        o;
}               t_data;

typedef struct      s_move
{
    int             x;
    int             y;
    struct s_move   *next;
}                   t_move;

int     getdata(t_data *data);
int     print_return(char *note, int ret, int fd);
int     solve(t_data *data);
void    printlist(t_move *list);
void    free_list(t_move **list);
void    get_moves(t_move **list, t_data *data);
void    mergesort_moves(t_move **list, t_data *data);
int     getpoints(t_move *move, t_data *data);

#endif