Project 1 
========================

1. CS162Project1_Bautista_Po_code.cpp
2. CS162Project1_Bautista_Po_testfile.text

Description
-----------

1. This file is C++ code that, when compiled and executed, simulates the different CPU scheduling algorithms, namely First Come First Serve, Priority, Shortest Remaining Time First, Round-Robin.

How to set up the program
-------------------------

If on Windows:

	1. Open a command line and navigate to the folder containing the files.

	2. If g++ compiler has not been installed on the machine yet, type in the following into the terminal:
		sudo apt-get install g++

	3. To create an executable program, type into the command line: g++ -o -<name of executable file> <name of program file>

If on Linux:
	1. If g++ compiler has not been installed on the Linux machine yet, type in the following into the terminal:
		sudo apt-get install g++

	2. To create an executable program, type into the command line: g++ -o -pthread <name of executable file> <name of program file>


How to use the program
----------------------
1. Open a command line and execute the program by navigating to the folder it is in and typing "./<name of executable file> <integer/s (separated by space if multiple)>"

2. The program will then take in and simulate the processes entered in the testfile.txt.

3. The program will calculate the CPU utilization, thorughput, waiting time, turnaround time and response time of each block of processes.

4. The command line will output the following:

4.1 Confirmation messages that the processes were simulated using the specified CPU scheduling algorithms

4.2 The gantt chart including the processes entered and the outputs

4.2.1 Time Elapsed in ns

4.2.2 Process Index

4.2.3 CPU time used in ns and if the process has been completed an 'X' after

4.3 The CPU utilization

4.4 Throughput

4.5 Waiting Time

4.6 Turnaround Time

4.7 Response Time
