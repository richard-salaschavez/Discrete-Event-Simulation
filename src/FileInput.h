/**
* Hold file and deals with file and line processing
*
* @author Richard Salas Chavez, 7764077
* @version June 27, 2016
*/

#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <string>
#include <fstream>

using namespace std;

class FileInput
{
private: 
	ifstream inFile;

public:
	FileInput(string fileName);
	void startFile();
	void readProcess();
	void makeProcess(string line);
	void close();
	~FileInput();
};
#endif
