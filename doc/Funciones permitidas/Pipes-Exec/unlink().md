`int unlink(const char *pathname);`

`unlink()` deletes a name from the filesystem. If that name was the last link to a file and no processes have it open, the file is deleted.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (unlink("temp.txt") == -1)
    {
        perror("unlink");
        return 1;
    }
    printf("File deleted\n");
    return 0;
}
```