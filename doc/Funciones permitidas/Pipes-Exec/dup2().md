`int dup2(int oldfd, int newfd);`

`dup2()` duplicates file descriptor `oldfd` to `newfd`, closing `newfd` first if necessary. If `oldfd` equals `newfd`, `dup2()` returns `newfd` without closing it.

Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        return 1;
    }
    printf("This goes to output.txt\n");
    close(fd);
    return 0;
}
```