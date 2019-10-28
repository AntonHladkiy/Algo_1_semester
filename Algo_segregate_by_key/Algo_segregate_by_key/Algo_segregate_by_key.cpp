#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pair {
public:
	int key;
	int value;
	Pair(int _key, int _value) {
		key = _key;
		value = _value;
	}
};
void function_1(std::vector<Pair>& vec) {
	std::vector<Pair> temp0;
	std::vector<Pair> temp1;
	for (const auto& item : vec) {
		if (item.key == 0) {
			temp0.push_back(item);
		}
		else {
			temp1.push_back(item);
		}
	}
	vec.clear();
	for (const auto& item : temp0) {
		vec.push_back(item);
	}
	for (const auto& item : temp1) {
		vec.push_back(item);
	}
}

void function_2(std::vector<Pair>& vec) {

		int type0 = 0;
		int type1 = vec.size() - 1;

		while (type0 < type1)
		{
			if (vec[type0].key == 1)
			{
				std::swap(vec[type0],vec[type1]);
				type1--;
			}
			else
				type0++;
		}
}


void function_3(std::vector<Pair>& vec) {

	for (int i = 0; i < vec.size(); i++) { //for all element
		for (int j = i + 1; j < vec.size(); j++) {
			if (vec[i].key > vec[j].key) {
				swap(vec[i], vec[j]);
				break;
			}
		}
	}

}

/* Driver code */
int main()
{
	std::cout << "O(n)+memory limitation" << std::endl;
	std::vector<Pair> vec = { Pair(0,2),Pair(1,3), Pair(1,4), Pair(0,5), Pair(0,6), Pair(1,10) };
	function_2(vec);
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i].key << " " << vec[i].value << std::endl;
	}
	std::cout << "O(n)+stable" << std::endl;
	std::vector<Pair> vec_1 = { Pair(0,2),Pair(1,3), Pair(1,4), Pair(0,5), Pair(0,6), Pair(1,10) };
	function_1(vec_1);
	for (int i = 0; i < vec_1.size(); i++) {
		std::cout << vec_1[i].key << " " << vec_1[i].value << std::endl;
	}
	std::cout << "stable+memory limitation" << std::endl;
	std::vector<Pair> vec_2 = { Pair(0,2),Pair(1,3), Pair(1,4), Pair(0,5), Pair(0,6), Pair(1,10) };
	function_3(vec_2);
	for (int i = 0; i < vec_2.size(); i++) {
		std::cout << vec_2[i].key << " " << vec_2[i].value << std::endl;
	}
}