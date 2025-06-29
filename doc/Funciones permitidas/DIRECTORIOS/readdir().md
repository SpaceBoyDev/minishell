`struct dirent *readdir(DIR *dirp);`

The `readdir()` function returns a pointer to a `dirent` structure representing the next directory entry in the directory stream pointed to by `dirp`. It returns `NULL` on reaching the end of the directory stream or if an error occurred.

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