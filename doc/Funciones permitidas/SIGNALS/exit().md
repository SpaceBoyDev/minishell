`void exit(int status);`

`exit()` terminates the calling process with the exit status specified by `status`.

Example:
```c
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    printf("Exiting program with status 0\n");
    exit(0);
}
```