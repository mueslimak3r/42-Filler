#include "libft.h"

int     ft_checkifc(char in, char c)
{
    if (in == c)
        return (1);
    if (c >= 'a' && c - 32 == in)
        return (1);
    if (c >= 'A' && c <= 'Z' && c + 32 == in)
        return (1);
    else
        return (0);
}