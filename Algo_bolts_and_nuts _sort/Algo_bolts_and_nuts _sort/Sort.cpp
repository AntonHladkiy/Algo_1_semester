#include "pch.h"
#include "Sort.h"


Sort::Sort(std::vector<int> _bolts, std::vector<int> _nuts): bolts(_bolts),nuts(_nuts)
{

}


Sort::~Sort()
{
}

void Sort::swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

int Sort::partition_bolts(int left,int right,int nut) { //розділення масиву болтів
	int pivot = nuts[nut];
	int left_pointer = left;
	for (int j = left; j < right; j++) {
		if (bolts[j] < pivot) {
			swap(bolts[left_pointer], bolts[j]);
			left_pointer++;
		}
		else if (bolts[j] == pivot) {
			swap(bolts[j], bolts[right]);
			j--;
		}
	}
	swap(bolts[left_pointer], bolts[right]);
	return left_pointer;
}

int Sort::partition_nuts(int left,int right,int bolt) {//розділення масиву гайок
	int pivot = bolts[bolt];
	int left_pointer = left;
	for (int j = left; j < right; j++) {
		if (nuts[j] < pivot) {
			swap(nuts[left_pointer], nuts[j]);
			left_pointer++;
		}
		else if (nuts[j] == pivot) {
			swap(nuts[j], nuts[right]);
			j--;
		}
	}
	swap(nuts[left_pointer], nuts[right]);
	return left_pointer;
}

void Sort::sort(int left, int right) {//рекурсивна функція сортування з вказаними межами
	if (left < right) {
		int p = partition_bolts(left, right, left);//розділеня масиву болтів та отримання вказівника на болт зі значенням nuts[left]
		partition_nuts(left, right, p);//розділення масиву гайок порівнюючи з значення болта в комірці p
		sort(left, p-1);//рекурсивний виклик функції для лівої частину масиву
		sort(p+1, right);//рекурсивний виклик функції для правої частини масиву
	}
}

void Sort::sort() {
	sort(0, bolts.size() - 1);
}

void Sort::output_check()
{
	for (int i = 0; i < bolts.size(); i++) {
		std::cout << bolts[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < nuts.size(); i++) {
		std::cout << nuts[i] << " ";
	}
	std::cout << std::endl;
}
