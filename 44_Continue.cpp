/*************************************************************************
    > File Name: Continue.cpp
    > Author: zy
    > Mail: 18220581367@163.com 
    > Created Time: 2016年05月26日 星期四 09时19分59秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

//升序排序
int compare(const void * argv1, const void * argv2)
{
	return *(int*)argv1 - *(int*)argv2;
}

bool IsContinuous(int * number, int length)
{
	if(number == NULL || length < 1)
	{
		return false;
	}

	//排序
	qsort(number, length, sizeof(int), compare);
	
	int numberOfZero = 0;
	int numberOfGap = 0;

	//统计0的个数
	for(int i = 0; i < length && number[i] == 0; ++i)
	{
		++numberOfZero;
	}

	//从非零处开始两两比较
	int small = numberOfZero;
	int big = small+1;
	while(big < small)
	{
		//若相等则不是顺子
		if(number[small] == number[big])
		{
			return false;
		}

		//计算之间相差的个数
		numberOfGap += number[big] - number[small] -1;
		//向下比较
		small = big;
		++big;
	}

	//判断0的个数和相差的个数，得出结果
	return (numberOfGap > numberOfZero) ? false:true;
}

//功能测试（抽出的牌中有一个或者多个大、小王，抽出的牌中没有大、小王，抽出的牌中有对子）
//特殊输入测试（输入NULL指针）

int main()
{
	int num[] = {
		5,3,1,2,0
	};
	if(IsContinuous(num, 5))
	{
		cout << "OK" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}

