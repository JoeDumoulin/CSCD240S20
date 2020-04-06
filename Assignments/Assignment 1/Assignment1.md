# Assignment 1

Download example code from this week's lectures and learn how to compile and run the code.  In this lab, we will use accounts on the cslinux server at Eastern's computing center.  There are som hoops to jump through to make that work.

## 1. Accessing the vpn
In order to use the cslinux system, you will need to download and run a vpn client to connect to the ewu vpn.  

### Mac and Windows Instructions:
Follow the instructions under "Installing VPN" on [this webpage](https://support.ewu.edu/support/solutions/articles/10000020118-how-do-i-connect-to-vpn-).

### Linux Instructions:
Only install on Linux if you already know how to use linux tools pretty well.  If you really want to try it, feel free to ask me how to do this

Next you need to get a terminal program running on the cslinux computer.  The terminal is where we will work with C and other tools to run programs.

In order to get the terminal running you will need to run the program **ssh** on your computer.

## 2. Getting **ssh** on your computer

### Mac Instructions:
Open the "terminal" application.  you should see a prompt.  Type the following into the terminal:

```ssh <<your ewu user id >>@cscd-linux01.eastern.ewu.edu``

For example, someone's user id might be ```ewarren05``` so I use the following string to log in through ssh:

```ssh ewarren05@cscd-linux01.eastern.ewu.edu```


### Windows Instructions:
Windows does not have a native terminal app but ther is an add-on called ```putty``` which can be installed and used for ssh.  ```putty``` can be found [here](https://www.chiark.greenend.org.uk/~sgtatham/putty/).  Install putty and then run it to get a terminal on the ```cscd-linux01.eastern.ewu.edu`` server.

### Linux Instructions:
Open the "terminal" application.  you should see a prompt.  type the following into the terminal:

```ssh <<your ewu user id >>@cscd-linux01.eastern.ewu.edu``

For example, someone's user id might be ```ewarren05``` so I use the following string to log in through ssh:

```ssh ewarren05@cscd-linux01.eastern.ewu.edu```

## 3. Work With the Example Programs From the Lecture
The first week's lectures include some example programs.  The remainder of this assignment will be to learn some basic linux terminal commands for navigation and file editing, and to do download, compile, and run the example programs from the lectures.

### Some Basic Terminal Commands We Need.
The linux terminal is where we will do most of our work this quarter.  The terminal has a rich variety of commands and capabilities but can be frustrating at time since you have to know how to use it before you use it.

We are going to use just a small subset of commands at first to:

* Find where we are
* Create a directory
* Change from one directory to another
* Download code
* Compile code
* Run our programs

In the following part of the lab, we are assuming that you have already connected to the vpn and run ```ssh``` to get a terminal on the cslinux computer.  If you have built your own local linux system, then these commands will work there as well.

When we successfully attach to the system, the screen looks like this:

![login image](/home/joe/Documents/CSCD240-001S20/media/ewu_cslinux_login.png) 

The ```$``` is where we can type by clicking  into the window.  If you press ```Enter``` you will see the terfminal advance down the screen.  Note the the mouse does not work in the terminal window.  It can be used to select text though.

For a general overview of linux terminal commands there are many good sources.  

[This page](https://faculty.ucr.edu/~tgirke/Documents/UNIX/linux_manual.html) has a lot of good advice.

#### Where Are We? - pwd
When you want to know where you are, you can type the command ```pwd```.  This command tells us where our terminal is currently pointing in the tree of directories on the computer's file system.  the terminal displays the directory information like this:

![pwd output](/home/joe/Documents/CSCD240-001S20/media/pwd_output.png) 

This shows that we are logged on to Eastern's system in our home directory.

#### New Directories and Navigation - mkdir and ls
Next we are going to make a new directory that is inside our home directory.  we do this with the command ```mkdir```.

At the terminal prompt, type

```mkdir projects``` and press ```Enter```.

This will create a new directory at the current location called 'projects'.

Now type ```ls``` and ```Enter```.

This will sow you the names of all directories and files at the current location. 

```mkdir``` stands for Make Directory.  This creates a new directory at the current location.

```ls``` stands for List Contents.  ```ls simply displays all the conents (directories and files) in the working directory.

#### Changing directories - cd
Next, type 

```cd projects``` and  ```Enter```.

Now you have changed the current location to be inside the new directory you created.   Your screen should look something like this:

![in the projects directory](/home/joe/Documents/CSCD240-001S20/media/after_cd_projects.png) 

You can see that the prompt has changed to show the current directory is "projects".

#### Downloading Source Code from github - git clone
Github is a very popular source code repository for open source and shared source.  You may have downloaded and used code from github before.  I guarantee you will do this in the furture if you stick with Computer Science as a carreer.

Github is built on a tool called 'git', which is written in C and is used by the maintainers of the Linux operating system to manage changes to the system.  git is a really important program for CS in industry.

Now we will use the command line version of git to get source code and other things from my github repository (repo).

Make sure you are in the projects folder by looking at the command prompt to see if it ends with ```~/projects$```.  If you are not in the projects directory, use ```cd projects``` to go there.

open a window in you browser and navigate to ```https://github.com/JoeDumoulin/CSCD240S20```.  This is my github page for this class.  The browser should display something like the following:

![github class repo](/home/joe/Documents/CSCD240-001S20/media/Github_page.png) 

Press the green button on the far right center of the page (Clone or Download) and then observe the text box that appears under "Clone with HTTPS".  This is the name of the repository that we will clone to our linux projects directory.

Next type 

```git clone https://github.com/JoeDumoulin/CSCD240S20.git``` and press ```Enter```.

This should start copying the repository to your projects directory.

When the prompt reappears,   type ```ls``` to see what was created by the clone.  

![git clone](/home/joe/Documents/CSCD240-001S20/media/git_clone.png) 

next, type 

```cd CSCD240S20/Hello``` and then type ```ls```.

You will see something like the following:

![source code directory](/home/joe/Documents/CSCD240-001S20/media/C_source_code.png) 

each for the file ending in ".c" is a C program source file.  We can display the contents of one of these files by using the ```cat``` command.

```cat hello.c```

You should see something like:

![cat hello.c](/home/joe/Documents/CSCD240-001S20/media/cat_hello_c.png) 

The screen is showing you the source code in the file.  Later on we will learn how to edit the files but for now, we are just going to comple and run ```hello.c```.  

#### Compiling the Code

Notice that near the top of the file there is a comment that begins 'compile with'.  This is the command needed to compile this program.  type the command (it starts with "gcc") into the the terminal and press ```Enter```.

If there are no errors in the source code, you should get no messages, just the next prompt.

#### Run Your Program
To run the program in the terminal, type the following

```./hello``` followed by ```Enter```

You should see something like the following.

![](/home/joe/Documents/CSCD240-001S20/media/Compile_and_run.png) 

### Other things to do

That's the end of the lab.  There is no grade, though we will have a quiz on some of these concepts and commands.  You can of course continue and compile other programs in the directory and run them to see what they do.

You can also look up the editor ```nano```.  search for ```nano``` in your web browser and look for how-to articles on how to use it.  We will use ```nano``` as an editor to to work with our programs as the class progresses.

Try using ```nano``` to modify the ```hello.c``` program to say hello to you.  Compile and run the program as abaove to see if your change worked.  If you get an error, what does it say?  what do you think it means?

