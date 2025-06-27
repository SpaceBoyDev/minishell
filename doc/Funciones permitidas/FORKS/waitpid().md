`pid_t waitpid(pid_t pid, int *wstatus, int options);`

`waitpid()` suspends execution of the calling process until the child specified by `pid` terminates. If `pid` is -1, `waitpid()` waits for any child process. `options` modifies behavior.

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
        return 7;
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```