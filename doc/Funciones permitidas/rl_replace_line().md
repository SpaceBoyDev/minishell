`int rl_replace_line(const char *text, int clear_undo);`

The `rl_replace_line()` function replaces the current line content with a new char * line. Useful if you want to autocomplete or autocorrect the user input. 

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
        if (strcmp(input, "magic") == 0)
        {
            rl_replace_line("¡Texto reemplazado por magia!", 1);
            rl_redisplay();
        }
        free(input);
    }
    return (0);
}
```