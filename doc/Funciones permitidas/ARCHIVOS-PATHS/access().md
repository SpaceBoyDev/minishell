`int access(const char *pathname, int mode);`

The function `access()` checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.
The mode specifies the accessibility check(s) to be performed, and is either the value F_OK, or a mask consisting of the bitwise OR of one or more of R_OK, W_OK, and X_OK. F_OK tests for the existence of the file. R_OK, W_OK, and X_OK test whether the file exists and grants read, write, and execute permissions, respectively.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    const char *filename = "test.txt";

    if (access(filename, F_OK) == 0)
        printf("%s existe.\n", filename);
    else
        printf("%s no existe.\n", filename);

    if (access(filename, R_OK) == 0)
        printf("Tienes permiso de lectura sobre %s.\n", filename);
    else
        printf("No tienes permiso de lectura sobre %s.\n", filename);

    return (0);
}
```