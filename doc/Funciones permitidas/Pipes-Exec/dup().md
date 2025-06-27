`int dup(int oldfd);`

`dup()` duplicates the file descriptor `oldfd`, returning a new file descriptor that refers to the same open file description.

Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    int copy = dup(fd);
    if (copy == -1)
    {
        perror("dup");
        return 1;
    }
    write(copy, "Hello\n", 6);
    close(fd);
    close(copy);
    return 0;
}
```