`pid_t wait3(int *wstatus, int options, struct rusage *rusage);`

`wait3()` suspends execution of the calling process until one of its children terminates. It returns resource usage information for the child via the `rusage` argument.

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
        return 3;
    }
    else
    {
        int status;
        struct rusage usage;
        wait3(&status, 0, &usage);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```