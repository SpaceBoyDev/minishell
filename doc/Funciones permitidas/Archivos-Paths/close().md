`int close(int fd);`

The `close()` function  closes  a  file descriptor, so that it no longer refers to any file and may be reused.

Example:
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    // ... usar el archivo ...
    if (close(fd) == -1)
        perror("close");
    else
        printf("Archivo cerrado correctamente\n");
    return (0);
}
```