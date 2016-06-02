#include <iostream>
#include <list>
using namespace std;

//方法一：用环形链表模拟圆圈
int LastRemaining(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	unsigned int i = 0;

	list<int> numbers;
	for (i = 0; i < n; ++i)
	{
		numbers.push_back(i);
	}
	list<int>::iterator current = numbers.begin();
	while (numbers.size() > 1)
	{
		for (int i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
			{
				current = numbers.begin();
			}
		}
		list<int>::iterator next = ++current;
		if (next == numbers.end())
		{
			next = numbers.begin();
		}

		--current;
		numbers.erase(current);
		current = next;
	}

	return *(current);
}

//方法二：
//f(n,m) = {0, n = 1; [f(n-1,m)+m]%n, n > 1}
int LastRemaining_(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; ++i)
	{
		last = (last + m) % i;
	}

	return last;
}

//功能测试（输入的m小于n，比如从最初有5个数字的
//圆圈删除每次第2、3个数字；输入的m大于或者等于n,
//比如从最初有6个数字的圆圈删除每次第6、7个数字）
//特殊输入测试（圆圈中有0个数字）
//性能测试（从最初有4000个数字的圆圈中每次删除第
//997个数字）

int main()
{
	cout << LastRemaining(5,2) << endl;
	cout << LastRemaining_(5, 2) << endl;
	return 0;
}