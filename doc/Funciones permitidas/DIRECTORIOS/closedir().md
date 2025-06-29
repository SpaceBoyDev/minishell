`int closedir(DIR *dirp);`

The `closedir()` function closes the directory stream associated with `dirp`. A successful call to `closedir()` also closes the underlying file descriptor associated with `dirp`. The directory stream descriptor `dirp` is not available after this call.

Example:
```c
#include <stdio.h>
#include <dirent.h>

int main(void)
{
    DIR *dir = opendir(".");
    if (dir == NULL)
    {
        perror("opendir");
        return (1);
    }
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return (0);
}
```