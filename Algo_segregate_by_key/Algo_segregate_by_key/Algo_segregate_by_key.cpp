#include "pch.h"
#include <iostream>
using namespace std;

/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(pair<int,int> arr[],
	int size)
{
	int type0 = 0;
	int type1 = size - 1;

	while (type0 < type1)
	{
		if (arr[type0].first == 1)
		{
			swap(arr[type0],
				arr[type1]);
			type1--;
		}
		else
			type0++;
	}
}

/* Driver code */
int main()
{
	pair<int,int> p(1,0);
	pair<int, int>  arr[] = { pair<int,int>(0,3), pair < int,int> (1,4), pair < int,int> (0,6), pair < int,int> (1,15), pair < int,int> (1,1), pair < int,int> (1,5),pair<int,int>(0,7) };
	int i, arr_size = sizeof(arr) / sizeof(arr[0]);

	segregate0and1(arr, arr_size);

	cout << "Array after segregation ";
	for (i = 0; i < 6; i++)
		cout << arr[i].second << " ";
	return 0;
}