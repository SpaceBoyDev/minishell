#include "../../libft/libft.h"

char	*ft_getenv(char *name, char **env)
{
	int		i;
	char	*needle;

	needle = ft_strjoin(name, "=");
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(needle, env[i], ft_strlen(needle)))
		{
			free(needle);
			return (&env[i][ft_strlen(name) + 1]);
		}
		i++;
	}
	return (NULL);
}