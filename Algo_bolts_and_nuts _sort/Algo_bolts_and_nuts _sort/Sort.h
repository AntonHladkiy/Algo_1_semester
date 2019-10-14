#pragma once
#include <vector>
#include <iostream>
class Sort
{
private:
	std::vector<int> nuts;//����� �����
	std::vector<int> bolts;//����� �����
	int partition_bolts(int, int, int);//��������� ������ �����
	int partition_nuts(int, int, int);//��������� ������ �����
	void sort(int, int);//���������� ������� ���������� � ��������� ������
	void swap(int&, int&);
public:
	void sort();//�������, �� ������� ���������� ����������
	void output_check();
	Sort(std::vector<int>, std::vector<int>);//�����������, ���� �������� ����� ����� �� �����
	~Sort();
};

