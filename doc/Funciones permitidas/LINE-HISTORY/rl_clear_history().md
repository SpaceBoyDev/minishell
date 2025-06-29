`void rl_clear_history(void);`

The `rl_clear_history()` function clears the history list by deleting all of the entries. The `rl_clear_history()` function frees data that the `readline` library saves in the history list.

Example:
```c
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *input;

	while ((input = readline("prompt> ")) != NULL)
    {
        if (!*input)
        {
            free(input);
            continue;
        }
        add_history(input);
        if (strcmp(input, "clearhist") == 0)
            rl_clear_history();
        free(input);
    }
    return (0);
}
```