`pid_t wait(int *wstatus);`

`wait()` suspends execution of the calling process until one of its children terminates. The termination status of the child is stored in the location pointed to by `wstatus`.

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
        return 42;
    }
    else
    {
        int status;
        wait(&status);
        if (WIFEXITED(status))
            printf("Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```