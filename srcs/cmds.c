#include "../inc/pipex.h"

char	*ft_paths(char **envp)
{
	while (!(ft_strnstr(*envp, "PATH", 5)))
		envp++;
	return(*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char *tmp;
	char *ret;
	
	if (access(cmd, 0) == 0)
			return (cmd);
	else
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			ret = ft_strjoin(tmp, cmd);
			if (access(ret, 0) == 0)
				return (ret);
			free(ret);
			paths++;
		}
		ft_error("get_cmd");
	}
	return (NULL);
}
