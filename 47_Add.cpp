#include <iostream>
using namespace std;

//不用加减乘除做加法
int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1 ^ num2;
		carry = (num1&num2) << 1;
		//两个数先做位与运算再左移一位

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

//输入正数、负数、0

int main()
{
	cout << Add(1,2) << endl;
	return 0;
}