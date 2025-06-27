`int ttyslot(void);`

`ttyslot()` returns the index in the utmp file corresponding to the current terminal.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int slot = ttyslot();
    if (slot == -1)
        perror("ttyslot");
    else
        printf("ttyslot: %d\n", slot);
    return 0;
}
```