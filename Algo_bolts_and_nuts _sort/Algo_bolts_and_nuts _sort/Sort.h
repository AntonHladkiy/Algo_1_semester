#pragma once
#include <vector>
#include <iostream>
class Sort
{
private:
	std::vector<int> nuts;//масив гайок
	std::vector<int> bolts;//масив болтів
	int partition_bolts(int, int, int);//розділення масиву болтів
	int partition_nuts(int, int, int);//розділення масиву гайок
	void sort(int, int);//рекурсивна функція сортування з вказаними межами
	void swap(int&, int&);
public:
	void sort();//функція, що викликає рекурсивне сортування
	void output_check();
	Sort(std::vector<int>, std::vector<int>);//конструктор, який ініціалізує масив болтів та гайок
	~Sort();
};

