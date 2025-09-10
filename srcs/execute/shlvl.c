#include "../lexer/lexer.h"
#include "../utils/utils.h"

char	**get_env_ref(char *str, t_data *data)
{
	int		i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(str, data->env[i], ft_strlen(str)))
		{
			return (&(data->env[i]));
		}
		i++;
	}
	return (NULL);
}

void	update_shlvl(t_data *data, int op)
{
	char	**ref;
	int		val;
	char	*new;
	char	*numstr;

	ref = get_env_ref("SHLVL=", data);
	val = ft_atoi(&((*ref)[ft_strlen("SHLVL=")]));
	new = (char *)malloc((ft_strlen(*ref) + 2) * sizeof(char));
	ft_strlcpy(new, "SHLVL=", ft_strlen(*ref) + 2);
	numstr = nbr_to_str(val + op);
	ft_strlcpy(&(new[6]), numstr, ft_strlen(*ref) + 2 - 6);
	free(numstr);
	free(*ref);
	*ref = new;
}
