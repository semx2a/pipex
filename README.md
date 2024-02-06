# Pipex

The Pipex project is a detailed exploration and programming of a UNIX pipe. The project is coded in C and adheres to the 42 School coding norm. This project served as an excellent opportunity to gain a deeper understanding of system calls and inter-process communication via pipes in a UNIX-like system.

## Usage 

You can launch the test script by running the following command:

```shell
chmod +x test.sh && ./test.sh

```

You can use the following arguments to run the test script:
```shell
./test.sh clean # Cleans the project
./test.sh bonus # Runs the bonus project tests
```

## Project Description

The Pipex project mimics the behavior of the following simple shell command:

```bash
< file1 cmd1 | cmd2 > file2

```

This command takes two commands - `cmd1` and `cmd2` - and two files - `file1` and `file2`. It runs `cmd1` with `file1` as input and `cmd2` with the output of `cmd1` as input. The final output of `cmd2` is then written into `file2`.

The Pipex program is executed in the following way:

```shell
./pipex file1 cmd1 cmd2 file2

```

## Skills Gained

Through this project, I have gained a deeper understanding of the following:

- The use of pipes for inter-process communication.
- The use of system calls such as `fork()`, `execve()`, `pipe()`, `dup()`, `dup2()`, and `waitpid()`.
- Handling and redirection of standard input, output and error.
- The use of file descriptors.
- Error handling and memory management in C, ensuring no memory leaks.
- Reading and understanding man pages.
- Working with Makefiles and libraries in C.
- Practical experience with Makefiles and libraries in C.

## Bonus

The Pipex project also ventured into additional complexities such as:

- Managing multiple pipes, which extends the functionality to this format:

```shell
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

```

This is identical to the shell command:

```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

```
