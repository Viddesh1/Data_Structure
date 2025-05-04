# Data_Structure
This repository contains the data structure implementation in C, C++ programming language.

### Installation (Windows 10)
Step 1: Wingw with base and C, C++ <br />

https://sourceforge.net/projects/mingw/ <br />
OR                                      <br />
Directly search for "wingw download"    <br />

After installing select the below packages to install for C, C++ along with gdb:- <br />

From Basic installation/setup:- <br />

1) wingw-developer-toolkit
2) wingw32-base
3) wingw32-gcc-g++
4) msys-base

Step 2: Set Environment path C:\MinGW\bin
1) Windows + R then type Edit environment variable
2) Click Environment Variables button
3) In System variables double click on Path
4) Click on New Button
5) Paste the path C:\MinGW\bin

Step 3: Open new terminal and check for below:-
1) g++ --version
2) gcc --version
3) gdb --version


# How to debug the program:
g++ 2-1.cpp -o 2-1    <br />
g++ -g 2-1.cpp -o 2-1 <br />
gdb ./2-1             <br />
break main            <br />
run                   <br />
