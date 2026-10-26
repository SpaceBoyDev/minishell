_This project has been created as part of the 42 curriculum by darmarti and marcolop._

# minishell

## Description

`minishell` is a small Unix shell written in C. It recreates the core behavior
of a command-line interpreter while handling parsing, environment variables,
processes, pipes, redirections, heredocs, signals, and memory management.

The project also includes a local [`libft`](./libft/), containing reusable
libft functions together with `ft_printf` and `get_next_line`.

## Features

- Interactive prompt powered by GNU Readline
- Single and double quotes
- Environment-variable expansion and `$?`
- Pipes (`|`)
- Input/output redirections (`<`, `>`, `>>`)
- Here-documents (`<<`)
- Built-ins: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`
- Interactive and non-interactive execution
- Signal handling for the shell and heredocs

## Requirements

- Unix-like operating system
- C compiler
- `make`
- GNU Readline development files

On Debian/Ubuntu, install the Readline dependency with:

```sh
sudo apt install libreadline-dev
```

## Build and run

```sh
make
./minishell
```

Useful Make targets:

```sh
make clean    # Remove object files
make fclean   # Remove object files and the executable
make re       # Rebuild from scratch
make norme    # Run Norminette checks
```

Commands can also be piped to the shell:

```sh
printf 'echo hello | tr a-z A-Z\n' | ./minishell
```

## Project structure

- `srcs/lexer/`: tokenization, quoting, and variable expansion
- `srcs/execute/`: pipelines, processes, redirections, and execution
- `srcs/builtins/`: shell built-in commands
- `srcs/heredoc/`: here-document handling
- `srcs/signals/`: signal configuration
- `srcs/utils/`: shell state, errors, and shared utilities
- `libft/`: supporting C library

## Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/)
- [`readline(3)`](https://man7.org/linux/man-pages/man3/readline.3.html)
- `pipe(2)`, `fork(2)`, `dup2(2)`, `execve(2)`, `waitpid(2)`, and `signal(2)`
