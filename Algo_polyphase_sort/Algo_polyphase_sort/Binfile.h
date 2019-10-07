#pragma once
#include <fstream>

using namespace std;

class BinFile
{
public:
	string fileName;
	bool done;
	streampos currentPos;
	BinFile();
	BinFile(string fName, int lengthOfRun);
};

