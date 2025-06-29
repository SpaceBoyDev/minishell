`int pipe(int pipefd[2]);`

`pipe()` creates a unidirectional data channel that can be used for interprocess communication. `pipefd[0]` is the read end, and `pipefd[1]` is the write end of the pipe.

Example:
```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int pipefd[2];
    char buffer[20];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return 1;
    }

    write(pipefd[1], "hello", 6);
    read(pipefd[0], buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
```