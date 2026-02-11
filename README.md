# Simple Shell Project
A minimal implementation of a UNIX command line interpreter.

## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
Interactive mode:
./hsh
($) /bin/ls

Non-interactive mode:
echo "/bin/ls" | ./hsh
