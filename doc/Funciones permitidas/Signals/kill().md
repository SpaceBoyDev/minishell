`int kill(pid_t pid, int sig);`

`kill()` sends the signal `sig` to the process specified by `pid`.

Example:
```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        while (1)
        {
            printf("Child running...\n");
            sleep(1);
        }
    }
    else
    {
        sleep(3);
        kill(pid, SIGKILL);
        printf("Sent SIGKILL to child\n");
    }
    return 0;
}
```