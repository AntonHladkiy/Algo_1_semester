#include "pch.h"
#include "Binfile.h"

BinFile::BinFile()
{
	fileName = "";
	int numberOfRuns = 0;
	int runLength = 0;
	done = false;
	currentPos = 0;
}

BinFile::BinFile(string fName, int lengthOfRun)
{
	fileName = fName;
	done = false;
	currentPos = 0;
}
