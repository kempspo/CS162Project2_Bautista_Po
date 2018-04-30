#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


int testcase;
int numprocess, numresource;
int check;

//checks for unfinished processes
int checkBool(int check[]){
	for(int i = 0; i < numprocess; i++){
		if(!check[i])
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	string sfile = argv[1];
	fstream file;
	file.open(sfile);

	int have[numprocess][numresource], need[numprocess][numresource];
	int resource[numresource];

	if( !file.is_open()){
		cout << "Unable to open file";
		exit(1);
	}
	/** looping through file for input **/
	file >> testcase;
	for(int i = 0; i < testcase; i++){
		file >> numprocess >> numresource;
		//gets available resources
		for(int j = 0; j < numresource; j++){
			file >> resource[j]; 
		}
		//gets resources each process has
		for(int j = 0; j < numprocess; j++){
			check[&i] = 0;
			for(int k = 0; k < numresource; k++){
				file >> have[j][k];
			}
		}
		//gets resources each process still needs
		for(int j = 0; j < numprocess; j++){
			for(int k = 0; k < numresource; k++){
				file >> need[j][k];
			}
		}
	}

	/** start doing stuff **/
	int counter = 0;
	int deadlock = 1;
	int finish[numprocess];
	int doneCount = 0;

	// just check until all processes are done
	while(!checkBool(&check)){
		for( int i = 0; i < numprocess; i++){
			deadlock = 1;
			if(check[&i] == 0){
				for(int j = 0; j < numresource; j++){
					//check if resource can be given to process by available
					if(need[i][j] <= resource[j]){
						counter++; // add to counter if allocated
					}
				}

				// if equal then it just means can already be filled
				if(counter == numresource)
				{
					check[&i] = 1;
					counter = 0;
					deadlock = 0;

					//allocate resource to process
					for(int k = 0; k < numresource; k++)
					{
						resource[k] += have[i][k];
					}

					finish[doneCount] = i + 1;
					doneCount++;
					//break;
				}				
			}
			counter = 0;
		}
	}	
		if(deadlock){
			cout << "Deadlock occured\n";
		}
		if(!deadlock){
			cout << "Process Request Order:\n";
			for(int i = 0; i < numprocess; i++){
				cout << finish[i];
			}
			cout << "\n";
		}
}
