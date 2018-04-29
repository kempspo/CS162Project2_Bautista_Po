#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc, char* argv[])
{
	string sfile = argv[1];
	fstream file;
	file.open(sfile);

	if( !file.is_open()){
		cout << "Unable to open file";
		exit(1);
	}

	int testcase;
	int numprocess, numresource;
	int resource[];
	int have[], need[];

	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		cin >> numprocess >> numresource;
		for(int j = 0; j < numresource; j++){
			cin >> resource[j]; 
		}
		for(int x = 0; x < (numprocess * numresource); x++){
			cin >> have[x];
		}
		for(int x = 0; x < (numprocess * numresource); x++){
			cin >> need[x];
		}
	} 
}