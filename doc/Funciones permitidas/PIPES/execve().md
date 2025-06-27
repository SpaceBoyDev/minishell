`int execve(const char *pathname, char *const argv[], char *const envp[]);`

`execve()` executes the program referred to by `pathname`, replacing the current process image. `argv` is an argument vector, and `envp` is an environment vector.

Example:
```c
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    char *args[] = { "/bin/ls", "-l", NULL };
    char *env[] = { NULL };

    execve("/bin/ls", args, env);
    perror("execve");
    return 1;
}
```