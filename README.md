# Pipex
This program simulates behavior of the pipes in bash

### Compiling

Run the following commands:

* To compile
	- `make`
* To remove objects:
	- `make clean`
* To remove objects and binary file (program):
	- `make fclean`
* To re-compile:
	- `make re`
  
### Executing

./pipex file1 cmd1 cmd2 file2

• file1 and file2 are file names.\
• cmd1 and cmd2 are shell commands with their parameters.

It must behave exactly the same as the shell command below:\
$> < file1 cmd1 | cmd2 > file2

### Examples

$> ./pipex infile "ls -l" "wc -l" outfile\
Behave like: < infile ls -l | wc -l > outfile\

$> ./pipex infile "grep a1" "wc -w" outfile\
Behave like: < infile grep a1 | wc -w > outfile
