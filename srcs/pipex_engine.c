#include "../inc/pipex.h"

void	ft_exec(char *arg, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(arg, ' ');
	path = ft_path(cmd[0], envp);
	if (execve(path, (char * const*)cmd, (char * const*)envp) == -1)
		ft_error("Could not execute path.");
}

char	*ft_path(char *src, char **envp)
{
	int	i;
	char	**dst;

	i = 0;
	dst = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			dst = ft_split(envp[i] + 5, ':');
			i = 0;
			while (dst[i])
			{
				dst[i] = ft_strjoin(dst[i], "/");
				dst[i] = ft_strjoin(dst[i], src);
				if (access(dst[i], X_OK) == 0)
					return (dst[i]);
				i++;
			}
		}
		i++;
	}
	return (0);
}