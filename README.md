

![Debugging Masterclass](title.png)
### The following is a guide to using the native Visual Studio Code interface for the LLDB low-level debugger.
  ---

**Prerequisite:** [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) from Microsoft	

 ---


Let's go ahead and open from the application menu bar at the top `File->New Window (⇧⌘N)` to work with.  

 - Select the newly opened window and do `File->Open... (⌘O)` and navigate to the directory which holds the files you wish to debug.  
 >Tip: Use ⌘↑ to navigate to the parent directory while selecting the directory in the Finder pop up. 

 - In  the Explorer view your project directory should appear as the root of the Workspace. This is important so that later in the .json files we can call this as ${workspaceFolder}.  
 
 [**Quick video of creating the following template configuration files**](https://vimeo.com/659664828)

 - Open the .c file you wish to debug. `ft_strcat.c` in case of this repo.  

 - Choose from the top-bar application menu `Terminal -> Run Build Task (⇧⌘B)`.

 - From the popped up list of detected tasks select the cogwheel (`Configure task`) from the right hand side of the task named `(C/C++: clang build active file, compiler: /usr/bin/clang)`.  

 - Inside .vscode directory (should be inside the root of our repo) `tasks.json` file should appear with a preconfigured setup.
 **This is one of the two crucial files in debugging with Visual Studio Code. Another one being `launch.json`**  

	> Tip: Hover your mouse over the variables for clarifying mouseover texts. 
 
From the file we can notice the `label` for the task; `command` to run, specifying our compiler: clang; and the `args` list.  

- Inside the arguments list we specify compilation flags and arguments, enclosed in double quotes and separated by commas and, for the sake of readibility, newlines.  

> Tip: Use Control+Spacebar for IntelliSense to see all contextually proper variable names. Navigate your cursor with arrow keys to change context and select an item from the list.  
>
> ![<Image of IntelliSense contextual menu>](https://i.imgur.com/nnkQwXo.png)

	"args": [
		"-g",
		"-Wall",
		"-Wextra",
		"-Werror",
		"-Wconversion",
		"-I${workspaceFolder}/libft/includes",
		"-L${workspaceFolder}/libft",
		"-lft",
		"${workspaceFolder}/libft/ft_strcat.c",
		"${workspaceFolder}/libft/ft_strlen.c",
		"${workspaceFolder}/libft/ft_strcpy.c",
		"${workspaceFolder}/mains/main.c",
		"-o",
		"${workspaceFolder}/binaries/ft_strcat_debug_binary"
	],

I like to use the ${workspaceFolder} variable which represents the root directory in the workspace. This is why we at first opened the directory. 

 - Specify all the paths to the files to be added to the compilation as usual. Prepend them with the absolute path of ${workspaceFolder}. Currently our files to be debugged reside in ${workspaceFolder}/libft/  

 - Add library inclusions and header search directories as usual.  

 - Give a descriptive and distinguishable name to the output file after "-o", since this is used later on in `launch.json`. 
 >**Warning: The compilation may overwrite any file that has the same name as specified in the output flag.**
 
 - Within options tag, update current working directory to your liking, usually to ${workspaceFolder}.

	- Change label as you see fit. Usually it's best to have descriptive words at the start of your label.

 - Save `tasks.json` (Autosave on delay or on focusChange feature enabled is highly recommended).
 
 - Activate (choose) the .c file to be debugged.  
 
 - Select `Run and Debug` icon from the left icon bar.  

 - Click on create a `launch.json` file.

 - Select the first element of the list: C++ (GDB/LLDB)  

 - Select again the first element of the list: clang - Build and debug active file (compiler: /usr/bin/clang)  

 It will now try to build your project and generate and launch it with a template `launch.json`. Check the status of the build from the temporary terminal that appears.  
In case of any error popups appear just cancel all of them.  

---

Let's now navigate to Explorer view and select the .vscode directory and from there choose `launch.json`.  

 - Change the program to match the output file name.  
preLaunchTask is the Label we chose in `tasks.json`.

 - Change the current working directory, cwd, to be ${workspaceFolder} or to any path that you wish any files the program creates to go into.  
 
 - If your main requires arguments, set them in double quotes in the comma-separated list of args.  

 - Activate the .c source file.  

 > Tip: Double click on a file (name or tab) to make it persist.  

 > Tip: The debugger has been coded to be strict about the type of the currently active file that has to be open once you begin debugging. For our use case .c extension works fine.  

 - Set a breakpoint on the first effective line of your function. In our **ft_strcat** select line **17**.  

 > Tip: Set the breakpoint by left clicking on the left hand-side of line numbers. A red circle should appear and stay.  
 >
 >![<Footage of setting a breakpoint>](https://videoapi-muybridge.vimeocdn.com/animated-thumbnails/image/6de2dd58-39ae-44ca-b23a-47b1eb1c2f4f.gif?ClientID=vimeo-core-prod&Date=1640257363&Signature=3e14c41096786ee4250355b80a5c92d611902b1a)

 - Go to `Run and Debug` menu.  

 - Start the debugger from the green play button.  
 
 > Tip: You might want to drag the Debug Console next to the terminal pane to view them both at the same time.  

 > Tip: Once executing `Run and Debug`, even if Build finished with errors, the selected launch.json rule is ran. This creates oddities with the debugger interface given that a previous working version of the program exists.  

 Now your program should have been built successfully and the debugger should halt the program on the line **17** we specified.  

 [**Video about debug procedure**](https://vimeo.com/659421992)

 Now a hovering bar of five buttons should appear.  

 > Tip: Drag the bar downwards from the left-hand side handle to prevent it from obstructing the view to the open tabs.  


 > Tip: Hover over the buttons to see more.  

  Now choose `Step into (F11)` to follow the function call one level deeper.  


  -  We are now within the **ft_strlen** function that is first called on the line we halted the program to.  
  
   - Observe from the left-hand pane the Variables section.  
 
  > Tip: As long as a variable is uninitialized, random values will appear.  
`Step over (F10)` the lines you wish to execute within **ft_strlen**.  


 > Tip: Observe from the left-hand side the interactive Call Stack, which shows every function call's stack frame in order. (Useful for inspecting recursion of putnbr.)  


 > Tip: Variables on call stack change throughout, they aren't saved as snapshots of stack frames.  


 > Tip: It isn't possible to retrace your steps so `Restart (⇧⌘F5)` the debugging whenever necessary, and after every change made to the sources.  

 ---
 Once the functionality has been verified, `Step out (F12)` from the function.  

 Now we are back at the line **17** the program first halted to. `Step into (F11)` once again now into the enclosing function call **ft_strcpy**.  

 - Set a breakpoint after the while loop on line **20** of ft_strcpy, and press `Continue (F5)` to skip to it.  

 - Check the results in Variables pane.  

 - `Step Out (F12)` from the function to return to **ft_strcat** source.  

  ---

  *Let's now concentrate on the Watch Expressions pane.*

 We can for example use our function to count the length of the string s2.  

 - Simply create a new watch expression with the value `ft_strlen(s2)`.  

 > Tip: Beware of using watch expressions or calling functions that modify the memory of the program once running. (Watch expressions are evaluated everytime the program halts.)  

 We can use the C library functions to compare the results in the watch expressions. Notice we need to cast the return to the desired type `(size_t)strlen(s2)`.  
 
 
 We can see strings (char *) from a specified location with `&string[position]`.  
 
 
 Basically anything is possible with the watch expressions as they have access to all the memory the program reserves.  
  
  
  For example `ft_test(src, dst, ref1) == ft_test(src, dst, ref2)`.  
  
  Test memory allocation failure handling by setting the recently successfully allocated pointer to NULL with `word[w] = NULL`. 
  
  >Tip: Run this only once and then remove the expression.  
  
  Stop the debugging with `Stop (⇧F5)`.  

---

> **Random tips:**
>  
>Tip: Infinite loops may run off and even though they disappear from the user interface they might stay in the background and slow down the computer. Relogging helps to solve this.  
>
>Tip: Even if the build fails, the debugger might appear to function, since it's been coded to assume the build is successful if there is a program with the correct name in the launch phase of the debugging.  
> 
>Tip: When you need to give input from the stdin to the program you are debugging, use `"externalConsole": true` to achieve this.  
>
>Tip: Any file you wish to debug must be added as a source to the compilation phase. Use the wildcard *.c to select all .c files of a directory.  
>
>Tip: Attaching a shell script as a dependency to tasks will help you debug projects which have prerequisite libraries to them.  
