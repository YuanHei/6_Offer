//和为s的两个数字VS和为s的连续正数序列
#include <iostream>
using namespace std;

//题目一：输入递增排序的数组和一个数字s，在数组中查找
//两个数字，使得他们的和正好为s。如果有多对数字的和
//等于s，输出任意一对即可

//功能测试（数组中存在和为s的两个数，数组中不存在和为
//s的两个数）
//特殊输入测试（表示数组的指针为NULL指针）

//方法一：时间复杂度高O(n*n)
void SumOfS(int num[], int out[], int n, int s)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (num[i] + num[j] == s)
			{
				out[0] = num[i];
				out[1] = num[j];
				return;
			}
		}
	}
}

//方法二：时间复杂度为O(n)
bool FindNumbersWithSum(int data[], int length, int sum,
	int & num1, int & num2)
{
	bool found = false;
	if (length < 1 || data == NULL )
	{
		return found;
	}
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		long long curSum = data[end] + data[start];

		if (curSum == sum)
		{
			num1 = data[start];
			num2 = data[end];
			found = true;
			break;
		}
		else if (curSum > sum)
		{
			end--;
		}
		else
		{
			start++;
		}
	}

	return found;
}

//题目二：输入一个正数s，打印出所有和为s的；连续正数序列
//（至少含有两个数）。
//例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，结果打印
//出3个连续序列

//功能测试（存在和为s的连续序列，如9、100等；不存在
//和为s的连续序列，如4，0）
//边界值测试（连续序列的最小和3）

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i < big + 1; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum < 3)
	{
		return;
	}
	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small, big);
		}
		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small, big);
			}
		}
		big++;
		curSum += big;
	}
}

int main()
{
	int num[] = { 1, 2, 4, 7, 11, 15 };
	int out[2] = { 0 };
	int num1 = 0, num2 = 0;
	SumOfS(num, out, 6, 15);
	for (int i = 0; i < 2; ++i)
	{
		cout << out[i] << " ";
	}
	cout << endl;
	if (FindNumbersWithSum(num, 6, 15, num1, num2))
	{
		cout << num1 << " " << num2 << endl;
	}
	int S;
	cin >> S;
	FindContinuousSequence(S);
	return 0;
}