#include "../inc/pipex.h"

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void	ft_free_tab(char **tab, long int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		len--;
	}
	free(tab);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
