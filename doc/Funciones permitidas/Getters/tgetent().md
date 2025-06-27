`int tgetent(char *bp, const char *name);`

`tgetent()` loads the entry for the terminal named `name` from the termcap database into the buffer `bp`.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int main(void)
{
    char buffer[2048];
    int status = tgetent(buffer, "xterm");
    if (status < 0)
        printf("Could not access termcap database\n");
    else if (status == 0)
        printf("Terminal type not defined\n");
    else
        printf("Termcap entry loaded\n");
    return 0;
}
```