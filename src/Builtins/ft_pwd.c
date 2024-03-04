#include "minishell.h"

int		ft_pwd(void)
{
	char	*cwd;

    cwd = ft_calloc(PATH_MAX, 1);
    if (!cwd)
        return (printf("Malloc Error\n"), ERROR);
	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, 1);
		return (SUCCESS);
	}
	return (ERROR);
}