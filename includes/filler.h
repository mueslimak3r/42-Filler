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
}               t_data;

typedef struct  s_move
{
    int         x;
    int         y;
    struct move *next;
}               t_move;

#endif