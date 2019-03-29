#include "../includes/filler.h"

int     print_return(char *note, int ret, int fd)
{
    ft_putstr_fd(note, fd);
    return (ret);
}

int     main(int ac, char **av)
{
    if (ac < 3 || !(*av[1] || *av[2]))
        return(print_return("too few arguments", 0, 2));
    
    return (0);
}