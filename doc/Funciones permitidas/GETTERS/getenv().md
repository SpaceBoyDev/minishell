`char *getenv(const char *name);`

`getenv()` searches the environment list for a string that matches `name` and returns the corresponding value.

Example:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *home = getenv("HOME");
    if (home)
        printf("HOME: %s\n", home);
    else
        printf("HOME not set\n");
    return 0;
}
```