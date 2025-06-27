`int tputs(const char *str, int affcnt, int (*putc)(int));`

`tputs()` outputs the string `str` to the terminal, calling the function `putc` for each character.

Example:
```c
#include <stdio.h>
#include <termcap.h>

int putchar_wrapper(int c)
{
    return putchar(c);
}

int main(void)
{
    char buffer[2048], *area = buffer;
    tgetent(buffer, "xterm");

    char *clear = tgetstr("cl", &area);
    if (clear)
        tputs(clear, 1, putchar_wrapper);

    return 0;
}
```