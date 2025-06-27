`int rl_on_new_line(void);`

The `rl_on_new_line()` function tells the update routine that we have moved onto a new empty line, usually used after outputting a line.

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
        add_history(input);
        // Simula que quieres preparar readline para una nueva línea
        rl_on_new_line();
        rl_redisplay();
        free(input);
    }
    return (0);
}
```
