`int rl_redisplay(void);`

The `rl_redisplay()` change what's displayed on the screen to reflect the current contents of `rl_line_buffer`.

Example:
```c
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *input;

    while ((input = readline("prompt> ")) != NULL)
    {
        if (strcmp(input, "show") == 0)
        {
            rl_replace_line("Esto es una nueva línea", 1);
            rl_redisplay(); // Redibuja la línea con el nuevo texto
        }
        free(input);
    }
    return (0);
}
```
