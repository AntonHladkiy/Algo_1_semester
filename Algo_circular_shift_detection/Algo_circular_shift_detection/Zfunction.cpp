#include "pch.h"
#include "Zfunction.h"


Zfunction::Zfunction(std::string T, std::string T_check):T(T),T_check(T_check)
{
}


Zfunction::~Zfunction()
{
}

std::vector<int> Zfunction::calc_z(const std::string& s) {
	const int len = s.length();
	std::vector<int> z;
	z.resize(len);
	z[0] = len;
	int l = 0, r = 0;
	int j;

	for (int i = 1; i < len; ++i) {
		if (i > r) {
			for (j = 0; (j + i < len) && (s[i + j] == s[j]); ++j);
			z[i] = j;
			l = i;
			r = i + j - 1;
		}
		else {
			if (z[i - l] < r - i + 1)
				z[i] = z[i - l];
			else {
				for (j = 1; (j + r < len) && (s[r + j] == s[r - i + j]); ++j);
				z[i] = r - i + j;
				l = i;
				r = r + j - 1;
			}
		}
	}
	return z;
}

void Zfunction::check_for_circular_shift()
{
	std::string new_string = T_check + T + T;//������ ����� ��������� ����� ������� T_check|T|T
	std::vector<int> z_function = calc_z(new_string);//������ ��� ����� ����� ����� ����� �� ������ ���������� ���� ��������� �������� � ���
	for (int i = 0; i < z_function.size() - 1; i++) {
		if (z_function[i] == T_check.length()) {//���� �������� ����� � ����� ����� ������� ������ ���������� ����� �� �� ������ �� � ����� ����� � ������� ���� ������� T_check, �� ���������� ����� ��������� �����
			std::cout << "It is a circular shift" << std::endl;
			return;
		}
	}
	std::cout << "It is NOT a  circular shift" << std::endl;
}
