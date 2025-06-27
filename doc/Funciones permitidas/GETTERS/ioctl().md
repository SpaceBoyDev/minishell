`int ioctl(int fd, unsigned long request, ...);`

`ioctl()` manipulates the underlying device parameters of special files. It can be used to control hardware devices.

Example:
```c
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(void)
{
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
    {
        perror("ioctl");
        return 1;
    }

    printf("Rows: %d, Columns: %d\n", ws.ws_row, ws.ws_col);
    return 0;
}
```