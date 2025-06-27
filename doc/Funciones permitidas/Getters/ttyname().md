`char *ttyname(int fd);`

`ttyname()` returns the name of the terminal device associated with file descriptor `fd`.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *name = ttyname(STDIN_FILENO);
    if (name)
        printf("Terminal name: %s\n", name);
    else
        perror("ttyname");
    return 0;
}
```