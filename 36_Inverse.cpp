#include <iostream>
using namespace std;

//数组中的逆序对
//在数组中的两个数字如果前面一个数字大于后面的数字，
//则这两个数字组成一个逆序对。输入一个数组，求这个
//数组中的逆序对

//方法一：O(n*n)
int Inverse(int num[], int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (num[i] > num[j])
			{
				count++;
			}
		}
	}
	return count;
}

//方法二：基于归并排序
//现将数组分割成子数组，先统计出子数组内部的
//逆序对的数目，然后统计出两个相邻子数组之间
//的逆序对的数目。在统计逆序对的过程中，还需
//要对数组进行排序。

//先用两个指针分别指向两个子数组的末尾
//并且每次比较两个指针指向的数字。如果第一个子数组
//中的数字大于第二个子数组中的数字，则构成逆序对
//并且逆序对的数目等于第二个子数组中剩余数字的个数
//如果第一个数组中的数字小于或等于第二个数组中的
//数字，则不构成逆序对。每一次比较的时候，我们都把
//较大的数字从后向前复制到辅助数组中，把相应的指针
//向前移位一位，进行下一轮比较

int InversePairsCore(int * data, int * copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	//i初始化为前半段最后一个数字的下标
	int i = start + length;
	//j初始化为后半段最后一个数字的下标
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
	{
		copy[indexCopy--] = data[i];
	}
	for (; j >= start + length + 1; --j)
	{
		copy[indexCopy--] = data[j];
	}

	return left + right + count;
}

int InversePairs(int * data, int length)
{
	if (data == NULL || length <= 0)
	{
		return 0;
	}

	int * copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = data[i];
	}

	int count = InversePairsCore(data, copy, 0, length-1);
	delete[] copy;

	return count;
}

//功能测试（输入未经排序的数组、递增排序的数组、递减排序的数组，
//输入的数组中包含重复的数字）
//边界值测试（输入的数组中只有两个数字、数组的数组只有一个数字）
//特殊输入测试（表示数组的指针为NULL指针）
int main()
{
	int num[] = { 7, 5, 6, 4 };
	cout << Inverse(num, 4) << endl;
	cout << InversePairs(num, 4) << endl;
	return 0;
}