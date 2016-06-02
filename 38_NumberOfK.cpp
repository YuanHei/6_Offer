#include <iostream>
using namespace std;
//数字在排序数组中出现的次数
//统计一个数字在排序数组中出现的次数。

//方法一：O(n)
int NumberCount(int num[], int n, int index)
{
	int count = 0;
	if (num == NULL)
	{
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (num[i] == index)
		{
			count++;
			if (num[i + 1] != index)
			{
				return count;
			}
		}
	}
}

//方法二
//k出现的第一个位置
int GetFirstK(int * data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		if ((middleIndex > 0 && data[middleIndex - 1] != k)
			|| middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (middleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}

	return GetFirstK(data, length, k, start, end);
}
//k出现最后一个位置
int GetLastK(int * data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k)
			|| middleIndex == length - 1)
		{
			return middleIndex;
		}
		else
		{
			start = middleIndex + 1;
		}
	}
	else if (middleData < k)
	{
		start = middleIndex + 1;
	}
	else
	{
		end = middleIndex - 1;
	}

	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int * data, int length, int k)
{
	if (data == NULL || length <= 0)
	{
		return 0;
	}
	int number = 0;
	int first = GetFirstK(data, length, k, 0, length - 1);
	int last = GetLastK(data, length, k, 0, length - 1);

	if (first > -1 && last > -1)
	{
		//位置相减得结果（k的个数）
		number = last - first + 1;
	}

	return number;
}

//功能测试（数组中包含查找的数字，数组中没有查找的数字，查找的数字在
//数组中出现一次或多次）
//边界值测试（查找数组中的最大值、最小值，数组中只有一个数字）
//特殊输入测试（表示数组的指针为NULL指针）

int main()
{
	int num[] = { 1, 2, 3, 3, 3, 3, 4, 5 };
	cout << NumberCount(num, 8, 3) << endl;
	cout << GetNumberOfK(num, 8, 3) << endl;
	return 0;
}