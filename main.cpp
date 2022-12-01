// =================================================================
//
// File: main.cpp
// Author: Fernanda Michelle Torres Aguilar
// Date: 28/11/2022
//
// =================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "codigoHash.h"

using namespace std;

unsigned int myHash1(const string s) {
	return (unsigned int) s[0];
}

int main(int argc, char* argv[]) {
	int lines, jobs;
	ifstream input (argv[1], ios::in);
	fstream output (argv[2], ios::out);

	if (argc != 3) {
		output << "Usage: " << " <input file> <output file>" << endl;
		return -1;
	}else if (!input) {
		output << "Error opening file " << argv[1] << endl;
		return -1;
	}else if (!output) {
		output << "Error opening file " << argv[2] << endl;
		return -1;
	}

	input >> lines;
	input >> jobs;

	

	HashTable<string, int> hash(lines, string("empty"), myHash1);

	for (int i = 0; i < lines; i++){
		string job;
		int time;
		input >> job >> time;
		hash.put(job, time);
	}

	for (int i = 0; i < jobs; i++){
		string job;
		int weight = 0;
		
		while (input >> job){
			if (job == "."){
				break;
			}
			weight += hash.get(job);
		}
		output << weight << endl;
	}

	input.close();
	output.close();

	return 0;
}
