`int tgetflag(char *id);`

`tgetflag()` gets the boolean value of a capability from the termcap entry.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int main(void)
{
    char buffer[2048];
    tgetent(buffer, "xterm");

    if (tgetflag("am"))
        printf("Terminal has automatic margins\n");
    else
        printf("No automatic margins\n");

    return 0;
}
```