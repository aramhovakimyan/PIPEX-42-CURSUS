# Pipex

Pipex is a multipipe providing tool developed as a project for 42 School. It provides a simple and efficient way to redirect the output of one command as the input to another command, allowing you to create complex data processing pipelines.

## Description

Pipex aims to simplify the process of redirecting input and output streams between multiple commands in the Unix-like operating system environment. It allows you to seamlessly connect commands together, enabling you to process data efficiently.

With Pipex, you can:

-   Execute a sequence of commands, with the output of each command becoming the input of the next.
-   Redirect input and output from/to files, as well as from/to standard input/output.
-   Specify the desired input and output file names conveniently.

By using Pipex, you can avoid the need to manually create temporary files or use complex shell commands to achieve the desired data processing flow. The tool provides a straightforward interface that allows you to focus on the logic of your data processing tasks, saving you time and effort.

## Installation

To use Pipex, you need to follow these steps:

1.  Clone the Pipex repository to your local machine:
    
    `git clone https://github.com/aramhovakimyan/PIPEX-42-CURSUS` 
    
2.  Navigate to the project directory:
        
    `cd pipex` 
    
3.  Build the executable by running the following command:
    
    `make` 
    
4.  Once the build process is complete, you can start using Pipex.
    

## Usage

To use Pipex, follow the general format:



`./pipex file1 cmd1 cmd2 file2` 

-   `file1` represents the input file that will be used as the initial input to the first command (`cmd1`).
-   `cmd1` is the first command to be executed, which will process the input from `file1`.
-   `cmd2` is the second command that will process the output of `cmd1`.
-   `file2` is the output file where the final result will be stored.

Make sure to replace `file1`, `cmd1`, `cmd2`, and `file2` with the actual file names and command names relevant to your specific use case.

## Examples

Here are a few examples to demonstrate the usage of Pipex:

1.  Process a file using two commands and save the result to a new file:
    
    `./pipex infile "cmd1" "cmd2" outfile` 
    
2.  Process the output of one command as the input to another command:
    
    `./pipex infile "cmd1" "cmd2" outfile` 
    

Feel free to explore different combinations of commands and input/output files to suit your specific needs.


## Contact

For any additional questions or inquiries, you can reach out to the project maintainer at [hovakimyan29@gmail.com](mailto:hovakimyan29@gmail.com).