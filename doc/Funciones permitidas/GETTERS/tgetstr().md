`char *tgetstr(char *id, char **area);`

`tgetstr()` retrieves the string value of a capability from the termcap entry.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int main(void)
{
    char buffer[2048], *area = buffer;
    tgetent(buffer, "xterm");

    char *clear = tgetstr("cl", &area);
    if (clear)
        printf("Clear string: %s\n", clear);
    else
        printf("Clear capability not found\n");

    return 0;
}
```