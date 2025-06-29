`pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage);`

`wait4()` suspends execution until the specified child terminates and returns information about the child's resource usage via `rusage`.

Example:
```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        return 4;
    }
    else
    {
        int status;
        struct rusage usage;
        wait4(pid, &status, 0, &usage);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```