`int open(const char *__file, int __oflag, ...);`

The  `open()` system call opens the file specified by pathname. If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().

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
    printf("Archivo abierto con descriptor %d\n", fd);
    close(fd);
    return (0);
}
```