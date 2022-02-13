

Debugging is about  
	- stepping forwards through the program execution  
	- understanding the behaviour of the program  
	- using breakpoints, conditional or not, to halt the execution  
	- pinpointing runtime errors (e.g SIGSEGV, the segmentation violation)  
	- locating logical errors  


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


