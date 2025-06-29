`int tgetnum(char *id);`

`tgetnum()` gets the numeric value of a capability from the termcap entry.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int main(void)
{
    char buffer[2048];
    tgetent(buffer, "xterm");

    int cols = tgetnum("co");
    printf("Terminal columns: %d\n", cols);

    return 0;
}
```