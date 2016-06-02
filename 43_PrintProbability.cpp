//n个骰子的点数
//把n个骰子仍在地上，所有骰子朝上一面的点数之和为s，
//输入n，打印出s的所有可能的值出现的概率

#include <iostream>
#include <math.h>
using namespace std;

//递归求解
int g_maxValue = 6;
void Probability(int original, int current, int sum, int * pProbabilities)
{
	if (current == 1)
	{
		pProbabilities[sum - original]++;
	}
	else
	{
		for (int i = 1; i < g_maxValue + 1; ++i)
		{
			Probability(original, current - 1, i + sum, pProbabilities);
		}
	}
}

void Probability(int number, int * pProbailities)
{
	for (int i = 1; i < g_maxValue + 1; ++i)
	{
		Probability(number, number, i, pProbailities);
	}
}

void PrintPribability(int number)
{
	if (number < 1)
	{
		return;
	}
	int maxSum = number * g_maxValue;
	int * pProbailities = new int[maxSum - number + 1];
	for (int i = number; i < maxSum + 1; ++i)
	{
		pProbailities[i - number] = 0;
	}

	Probability(number, pProbailities);

	int total = pow((double)g_maxValue, number);
	for (int i = number; i < maxSum + 1; ++i)
	{
		double ratio = (double)pProbailities[i - number];
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbailities;
}

//方法二:循环求解
void PrintProbability_(int number)
{
	if (number < 1)
	{
		return;
	}

	int * pProbabilities[2];
	pProbabilities[0] = new int[g_maxValue * number + 1];
	pProbabilities[1] = new int[g_maxValue * number + 1];
	for (int i = 0; i < g_maxValue * number + 1; ++i)
	{
		pProbabilities[0][i] = 0;
		pProbabilities[1][i] = 0;
	}

	int flag = 0;
	for (int i = 1; i < g_maxValue + 1; ++i)
	{
		pProbabilities[flag][i] = 1;
	}

	for (int k = 2; k < number + 1; ++k)
	{
		for (int i = 0; i < k; ++i)
		{
			pProbabilities[1 - flag][i] = 0;
		}

		for (int i = k; i < g_maxValue * k + 1; ++i)
		{
			pProbabilities[1 - flag][i] = 0;
			for (int j = 1; j < i + 1 && j < g_maxValue + 1; ++j)
			{
				pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
			}
		}
		flag = 1 - flag;
	}

	double total = pow((double)g_maxValue, number);

	for (int i = number; i < g_maxValue * number + 1; ++i)
	{
		double ratio = (double)pProbabilities[flag][i] / total;
		printf("%d: %e\n", i, ratio);
	}

	delete[] pProbabilities[0];
	delete[] pProbabilities[1];
}

//功能测试 (1,2,3,4个骰子的各点数的概率)
//特殊输入测试 (输入0)
//性能测试 (输入较大的数字，比如11)

int main()
{
	int s;
	cin >> s;
	PrintPribability(s);
	PrintProbability_(s);
	return 0;
}
