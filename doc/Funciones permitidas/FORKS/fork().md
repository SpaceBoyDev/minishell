`pid_t fork(void);`

`fork()` creates a new process by duplicating the calling process. The new process is referred to as the child process. It differs from the parent process only in its process ID and parent process ID.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process\n");
    }
    else
    {
        printf("Parent process, child PID: %d\n", pid);
    }

    return 0;
}
```