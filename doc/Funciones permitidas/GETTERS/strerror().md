`char *strerror(int errnum);`

`strerror()` returns a pointer to the textual representation of the error number `errnum`.

Example:
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    FILE *f = fopen("nonexistent.txt", "r");
    if (!f)
    {
        printf("Error: %s\n", strerror(errno));
    }
    return 0;
}
```