`int tcgetattr(int fd, struct termios *termios_p);`

`tcgetattr()` gets the current parameters associated with the terminal referred to by `fd`.

Example:
```c
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
    struct termios t;

    if (tcgetattr(STDIN_FILENO, &t) == -1)
    {
        perror("tcgetattr");
        return 1;
    }

    printf("Terminal input flags: %x\n", t.c_iflag);
    return 0;
}
```