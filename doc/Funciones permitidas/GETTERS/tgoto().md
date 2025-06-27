`char *tgoto(const char *cap, int col, int row);`

`tgoto()` returns a cursor addressing string decoded from a termcap capability, given the column and row.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int main(void)
{
    char buffer[2048], *area = buffer;
    tgetent(buffer, "xterm");

    char *cm = tgetstr("cm", &area);
    if (cm)
    {
        char *s = tgoto(cm, 10, 5);
        printf("Cursor movement string: %s\n", s);
    }

    return 0;
}
```