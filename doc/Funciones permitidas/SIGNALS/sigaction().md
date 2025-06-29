`int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`

`sigaction()` examines and changes the action associated with a specific signal `signum`.

Example:
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Handled signal %d\n", sig);
}

int main(void)
{
    struct sigaction sa;
    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);
    while (1)
    {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
```