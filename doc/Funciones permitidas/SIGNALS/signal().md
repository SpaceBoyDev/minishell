`sighandler_t signal(int signum, sighandler_t handler);`

`signal()` sets a function to handle the signal specified by `signum`. When the signal is received, the specified `handler` is invoked.

Example:
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main(void)
{
    signal(SIGINT, handle_sigint);
    while (1)
    {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}
```