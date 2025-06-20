/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 18:30:04 by dario             #+#    #+#             */
/*   Updated: 2025/06/10 20:32:15 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define BLUE	"\033[1;34m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"

# define BG_RST    "\033[0m"
# define BG_RED    "\033[41m"
# define BG_GREEN  "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE   "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN   "\033[46m"
# define BG_WHITE  "\033[47m"

typedef enum e_token_type {
    STR,
    PIPE,
    IN,
    OUT,
    APPEND,
    HEREDOC,
} t_token_type;

typedef struct s_token {
    t_token_type    type;
    char            *str;
    struct s_token  *next;
} t_token;
