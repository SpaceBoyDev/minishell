`int stat(const char *restrict pathname, struct stat *restrict statbuf);`
`int lstat(const char *restrict pathname, struct stat *restrict statbuf);`
`int fstat(int fd, struct stat *statbuf);`

These functions return information about a file in the structure pointed to by `statbuf`.