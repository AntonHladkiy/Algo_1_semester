// Algo_polyphase_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "PolyphaseMergeSort.h"
#include <time.h>

using std::cout;

void GenerateFile(string fname, int count) {
	srand(time(0));
	fstream f;
	f.open(fname, std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
	int32_t val;
	for (int i = 0; i < count; i++)
	{
		val = rand() % 10000000;
		f.write((char*)& val, sizeof(val));
	}
	f.close();
}

int fSize(string filename) {
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	int size = in.tellg();
	in.close();
	return size;
}

void OutFile(string fname) {
	ifstream  f;
	int inputSize = fSize(fname);
	f.open(fname, ios::in | ios::binary);
	f.seekg(0, ios::beg);
	int32_t val;
	while (f.tellg() < inputSize)
	{
		f.read((char*)& val, sizeof(val));
		cout << val << " ";
	}
	f.close();
}

int main()
{
	GenerateFile("inp.dat", 10);
	cout << "Start" << endl;
	PolyphaseMergeSort sort;
	int numberOfFiles = 5;
	sort.polyphaseMergeSort("inp.dat", 3, numberOfFiles);
	OutFile("F0.dat");

}
