`int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);`

`tcsetattr()` sets the terminal attributes for the terminal referred to by `fd`.

Example:
```c
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int main(void)
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ECHO; // disable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    printf("Echo disabled. Type something: ");
    getchar();

    t.c_lflag |= ECHO; // re-enable echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    printf("\nEcho re-enabled.\n");

    return 0;
}
```