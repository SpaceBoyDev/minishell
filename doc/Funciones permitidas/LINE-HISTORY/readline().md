`char *readline (const char *prompt);`

The [`readline()`](https://man7.org/linux/man-pages/man3/readline.3.html). function reads a line from the terminal and returns it, using `prompt` as a prompt. If no prompt is given as parameter, no prompt will be shown in the terminal. The line returned is allocated with `malloc` and we have to free it ourselves.

Example:
```c
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void)
{
    char *rl;
    rl = readline("Prompt > ");
    printf("%s\n", rl);
    return (0);
}
```

Result:
```
$> ./minishell
Prompt > Hi ! How are you ?
Hi ! How are you ?
$>
```