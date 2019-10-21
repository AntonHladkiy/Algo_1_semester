#pragma once
#include <iostream>
#include <vector>
#include <string>
class Zfunction
{
private:
	std::string T;
	std::string T_check;
public:
	Zfunction(std::string T,std::string T_check);
	~Zfunction();
	std::vector<int> calc_z(const std::string&);//функція яка вираховує спеціальний масив чисел згідно якого можна буде сказати чи є текстовий рядок циклічним зсувом
	void check_for_circular_shift();
};

