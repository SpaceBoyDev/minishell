`int chdir(const char *path);`

`chdir()` changes the current working directory of the calling process to the directory specified in `path`.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (chdir("/tmp") == -1)
    {
        perror("chdir");
        return 1;
    }
    printf("Directorio cambiado a /tmp\n");
    return 0;
}
```