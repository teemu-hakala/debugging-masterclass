

Debugging is about  
	- stepping forwards through the program execution  
	- understanding the behaviour of the program  
	- using breakpoints, conditional or not, to halt the execution  
	- pinpointing runtime errors (e.g SIGSEGV, the segmentation violation)  
	- locating logical errors  

One great thing about VSCode IDE is it's debugging capabilities. Whether you are seasoned developer or just starting off with the programming, debugger is an essential tool to have at your disposal. 

What kind of situations call for the debugger? Say, your function doesn't return what you expect it to; or your program exits with nasty Segmentation fault, or Bus error; or even worse -- your program works as intended, but you have no idea why. 

Debugger helps you execute your code line by line, showing you exactly what is inside every variable you have, and how the this contents change with each operation. 

Sounds great? We're just getting started, for with debugger you can send any value to a variable on-the-fly and observe how it affects your code, watch external expressions and functions results that take inputs from your code as an arguments (think unit tests), read memory addresses of a pointers, return values of printf and write (and any other) functions and so much more. 

A good introduction level debugger to wrap your head around the concept would be [PythonTutor](https://pythontutor.com/). It is a great way to visualize our function's execution logic, but it is not always accessible due to their server's bandwidth limitations, it is somewhat slow and it's getting extremely uncomfortable to put together codebase that consists of more than couple of function in there. Another major point, is that using web-based tool for somethign as intimate as dissecting your own code is just very uncool for a capable programmer as oneself. 

VSCode allows you to run debugger native to your platform (lldb on MacOS) from within the IDE. As a configuration it uses couple of JSON files, and you know what these are, [right](https://www.json.org/json-en.html)?. Main 'entry' file would be tasks.json - basically what it does is that first it describes the compilation procedure for the program-in-question (```gcc main.c function.c -g -o myprogram``` etc, you know the drill, remember the -g flag for debugger info) in form of object notation(ON in JSON), specifies the compiler to use (gcc, clang or whatever), and puts a Label to all this process. 

Label is used in another JSON file - launch.json. In there we describe which tasks to perform on debugger's launch. Also in there it is possible to set ```stopAtEntry``` parameter to true, so our debugger halt the execution in the very beginning and let us control the flow by pressing forward arrow step-by-step. Otherwise the flow will just run to the very end, as it usually does. 

To control the entrypoint to debuggin procedure, we can use breakpoints. By clicking to left of the line number in your code you can place a red dot next to it. When the execution flow will come to this point, it will hit the emergency brakes and will allow you to inspect whatever you have in each of you variables and proceed with the execution manually. Of course you will still be able to just unpress the 'brakes' and let the code flow freely again. 

With all the data in place we open the file in editor for the debugger always targets the file in the active window, - and voila, you are able to step through your code. 


---
## **tasks.json**  
- `Makefile` integration  
- a task may dependsOn of another task for dividing the tasks into reusable blocks  

---
## **launch.json**  
- `preLaunchTask` ties the task calling a shell script or a Makefile into the launch rule  
- `externalConsole: true` prints the character as they would appear in the terminal, whereas false outputs to the `DEBUG CONSOLE` which cannot show colours for example  

---
## **Debug Console**
- feed the low-level debugger commands to execute.


