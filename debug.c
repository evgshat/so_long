#include "mlx/mlx.h"
// # include "mlx/mlx_int.h"
#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	debug(char *msg, int debug)
{
	if (debug == 1)
	{
		ft_putstr_fd(msg, 1);
	}
}
