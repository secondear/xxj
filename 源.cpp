#include<iostream>
#include <stdlib.h>
using namespace std;
int MaxsumUlt(int* arr, int subs)
{
	if (arr == NULL)
		return 0;

	int Sum = arr[0];   
	int MAX = 0;   

	for (int i = 1; i < subs; i++)
	{
		if (Sum <= 0)
		{
			Sum = arr[i];
		}
		else
		{
			Sum += arr[i];
		}
		if (Sum >= MAX)
			MAX = Sum;
	}
	return MAX;		
}

int main()
{
	int array[] = { -2,11,-4,13,-5,-2 };
	int subs = sizeof(array) / sizeof(array[0]);
	int MAX = MaxsumUlt(array, subs);
	cout << MAX << endl;
	system("pause");
	return 0;
}