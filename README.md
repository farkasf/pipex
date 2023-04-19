# pipex
*Many pipes make a pipeline*

This project is about creating a program that simulates a pipeline of commands simialar to the Unix shell command "pipe" in C language. "pipex" takes a filename for input and a filename for output, together with a list of commands to run on the input before writing to the output file.

<p align="center">
  <img width="256" height="256" src="resources/Hotpot_matrix_pipes.png">
</p>

### What is the approach?
1. take in 4+ command arguments (files to use and commands to run)
2. create a pipe to allow communication between the child and the parent
3. fork 2 processes to execute each of the commands
* one child for file reading from the input and writing to the pipe
* the other child reading from the pipe and writing to the next pipe/output file
4. make the parent wait for both child processes to finish and exit
5. execute commands by <code>execve</code> and redirect to the file descriptors by <code>dup2</code>

### What kind of input does the program take?
| use            | pipex input                                                     | shell command                                                 |
|----------------|-----------------------------------------------------------------|---------------------------------------------------------------|
| one pipe       | <code>./pipex input cmd1 cmd2 output</code>                     | <code>input cmd1 \| cmd2 > output</code>                      |
| multiple pipes | <code>./pipex input cmd1 cmd2 .. cmdn output</code>             | <code>input cmd1 \| cmd2 \| cmdn > output</code>              |
| here_doc       | <code>./pipex here_doc LIMITER cmd1 cmd2 ... cmdn output</code> | <code>cmd << LIMITER \| cmd1 \| cmd2 \| cmdn >> output</code> |
