`char *getcwd(char *buf, size_t size);`

The `getcwd()` returns a null-terminated string containing the absolute pathname that is the current working directory of the calling process. The pathname is returned as the function result and via the argument `buf`.

Example:
```c
#include <unistd.h>
#include <stdio.h> // for printf

int main(void)
{
    char *pwd;
    
    pwd = getcwd(NULL, 0);
    printf("pwd: %s\n", pwd);
    return (0);
}
```

Result:
```
$> pwd: /Users/saeby/Documents/tmp
```