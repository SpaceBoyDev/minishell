`void perror(const char *s);`

`perror()` prints a descriptive error message to `stderr`. The message includes the string `s`, followed by a colon, a space, and the error message.

Example:
```c
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("nonexistent.txt", "r");
    if (!f)
    {
        perror("fopen");
    }
    return 0;
}
```