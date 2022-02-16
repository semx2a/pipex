#include "../inc/pipex.h"

static size_t	ft_count(char const *s, char a)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != a)
		i++;
	return (i);
}

static void    ft_free_tab(char **tab, int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		len--;
	}
	free(tab);
}

static void	ft_substrcpy(char const *s, char a, char **d)
{	
	size_t	w_count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (ft_count(s + i, a))
		{
			w_count = 0;
			w_count = ft_count(s + i, a);
			d[j] = ft_substr(s + i, d[j], 0, w_count);
			if (ft_strlen(d[j]) != w_count)
				return(ft_free_tab(d, j));
			i = i + w_count + 1;
			j++;
		}
	}
}

char	**ft_split(char const *s, char a)
{
	char		**d;
	size_t	t_count;
	size_t			i;

	if (!s)
		return (NULL);
	t_count = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != a && (!s[i + 1] || s[i + 1] == a))
			t_count++;
		i++;
	}
	d = (char **)malloc(sizeof(char *) * (t_count + 1));
	if (!d)
		return (NULL);
	ft_substrcpy(s, a, d);
	d[t_count] = 0;
	return (d);
}
