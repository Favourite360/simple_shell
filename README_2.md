<center><h1>Readme of our approach to the project in progress - Bugs and Fixes - Emmanuel & Khawla.</h1> </center>

## Bug 1
-  Problem: Still emulating the same error output as the Thompson Shell
	- I had previously used `perror(argv[0]`); to print error to the stderr. However this was limited in terms of cusomizing the message further as I'd want (i.e: `./hsh: 1: /bin/tth: not found`).
-  Solution: had to create a custom err_msg function to receive multiple arguments (see file - `99-err_msg.c`), thus allowed to pass in the file descriptor, command count, name of the command and custom message. 


## Bug 2
-  Problem:  Memory Leaks at every time that ENTER key is pressed multiple times with no command (i.e \n \n \n \n).
-  Solution: Still working on this...


## Bug 3
-  Problem: Memory Leaks when command not found
-  Solution: Still working...	

## Bug 4:
-  Problem: Duplicate execution of command when (Having implemented PATH - to enable global execution of commands).
-  Solution: Still working...
