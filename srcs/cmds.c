#include "../inc/pipex.h"

char	*ft_paths(char **envp)
{
	while (ft_strnstr(*envp, "PATH", 4))
		envp++;
	return(*envp + 5);
}

char	*get_cmd(char **paths, char *cmd)
{
	char *tmp;
	char *ret;
	
	if (access(cmd, X_OK))
			return (cmd);
	else
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			ret = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(ret, X_OK) == -1)
				return (ret);
			free(ret);
			paths++;
		}
	}
	return (NULL);
}
