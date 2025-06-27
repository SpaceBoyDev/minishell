`ssize_t read(int fd, void buf[.count], size_t count);`

The `read()` function attempts to read up to count bytes from file descriptor `fd` into the buffer starting at buf.

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
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }
    buffer[bytes_read] = '\0'; // Asegura que el buffer sea una string válida
    printf("Leído: %s\n", buffer);
    close(fd);
    return (0);
}
```