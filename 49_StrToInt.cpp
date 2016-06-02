//在C++中，成员变量的初始化顺序只与它们在类中声明的顺序有关，而与在初始化列表中的顺序无关。
//把字符串转换成整数
#include <iostream>
using namespace std;

enum Status{ kVaild = 0, kInvauld };
int g_nStatus = kVaild;

long long StrToIntCore(const char * digit, bool minus)
{
	long long num = 0;
	while (*digit != '\0')
	{
		if (*digit >= '0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');

			//判断溢出
			if ((!minus && num > 0x7FFFFFFF)
				|| (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if (*digit == '\0')
	{
		g_nStatus = kVaild;
	}

	return num;
}

int StrToInt(const char * str)
{
	g_nStatus = kInvauld;
	long long num = 0;

	if (str != NULL && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
		{
			str++;
		}
		else if (*str == '-')
		{
			str++;
			minus = true;
		}

		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}

	return (int)num;
}

//功能测试（输入的字符串表示正数、负数和0）
//边界值测试（最大的正整数、最小的负整数）
//特殊输入测试（输入字符串为NULL指针、输入字符串
//为空字符串、输入的字符串中有非数字字符等）

int main()
{
	char str[] = "123";
	cout << StrToInt(str) << endl;
	return 0;
}