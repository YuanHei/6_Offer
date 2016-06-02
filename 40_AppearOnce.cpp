//数组中只出现一次的数字
//一个整型数组里除了两个数字之外，其他的数字都出现两次。
//请写程序找出这两个只出现一次的数字。
//要求时间复杂度是O(n),空间复杂度为O(1)

#include <iostream>
using namespace std;

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumsAppearOnce(int data[], int length, int * num1, int * num2)
{
	if (NULL == data || length < 2)
	{
		return;
	}
	
	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = 0; 
	*num2 = 0;

	for (int j = 0; j < length; ++j)
	{
		if (IsBit1(data[j], indexOf1))
		{
			//根据indexOf1位是否为1来进行划分，变成两个数组
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}
}

//功能测试（数组中多对重复的数字，数组中没有重复的数字）
int main()
{
	int num[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int num1, num2;
	FindNumsAppearOnce(num, 8, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	return 0;
}