`int isatty(int fd);`

`isatty()` returns 1 if the file descriptor `fd` refers to a terminal, and 0 otherwise.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (isatty(STDIN_FILENO))
        printf("stdin is a terminal\n");
    else
        printf("stdin is not a terminal\n");
    return 0;
}
```