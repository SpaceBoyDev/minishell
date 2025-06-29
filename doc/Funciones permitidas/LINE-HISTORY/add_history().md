`void add_history(char *s);`

The `add_history()` function saves the line passed as parameter in the history so it can be retrieved later in the terminal (like pressing the up arrow in bash).

Example:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *input;

    while ((input = readline("prompt> ")) != NULL)
    {
        if (*input) // Solo añade líneas no vacías
            add_history(input);
        free(input);
    }
    return (0);
}
```