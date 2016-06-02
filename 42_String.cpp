//翻转单词顺序VS左旋转字符串
//题目一：
//输入一个英语句子，翻转句子中单词的顺序，但单词内字符的
//顺序不变。为简单起见，标号符号和普通字母一样处理。
//例如：输入字符串“I am a student”，则输出“student a am I”
#include <iostream>
using namespace std;

//翻转函数
//功能测试（句子中有多个单词，句子中只有一个单词）
//特殊输入测试（字符串指针为NULL指针、字符串的内容为
//空、字符串中只有空格）
void ReverWord(char * pBegin, char * pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}
	char tmp;
	while (pBegin < pEnd)
	{
		tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;

		pBegin++;
		pEnd--;
	}
}

//将字符串根据空格和'\0'划分成多个字符串
char * Reverse(char * str)
{
	if (NULL == str)
	{
		return NULL;
	}
	char * pBegin = str;
	char * pEnd = str;

	while (*pEnd != '\0')
	{
		pEnd++;
	}
	pEnd--;

	ReverWord(pBegin, pEnd);

	pBegin = str;
	pEnd = str;

	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if ((*pEnd == ' ') || (*pEnd == '\0'))
		{
			ReverWord(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return str;
}

//题目二：字符串的左旋转操作是把字符串前面的若干个
//字符转移到字符串的尾部。请定义一个函数实现字符串左旋转
//操作的功能。比如输入字符串“abcdefg”和数字2，该函数将
//返回左旋转2位得到的结果“cdefgab”。

//方法一：空间时间复杂度都为O(n)
char * LeftReverse(char * str, int index, int n)
{
	int k = 0;
	char * tmp = new char[n];
	memset(tmp, '\0', n);

	for (int i = index; i < n; ++i)
	{
		tmp[k++] = str[i];
	}
	for (int i = 0; i < index; ++i)
	{
		tmp[k++] = str[i];
	}
	tmp[k] = '\0';
	return tmp;
}

//方法二:将字符串从n的位置分开，将两部分的字符串分别翻转，
//最后翻转整个字符串
//功能测试（把长度为n的字符串左旋转0、1、n-1、n、n+1个字符）
//特殊输入测试（字符串的指针为NULL的指针）
char * LeftRotateString(char * pStr, int n)
{
	if (pStr != NULL)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n > 0 && n < nLength)
		{
			char * pFirstStart = pStr;
			char * pFirstEnd = pStr + n - 1;
			char * pSecondStart = pStr + n;
			char * pSecondEnd = pStr + nLength - 1;

			ReverWord(pFirstStart, pFirstEnd);
			ReverWord(pSecondStart, pSecondEnd);
			ReverWord(pFirstStart, pSecondEnd);
		}
	}

	return pStr;
}

int main()
{
	char str[] = "I am a student";
	char str1[] = "abcdefg";
	cout << Reverse(str) << endl;
	cout << LeftReverse(str1, 4, 7) << endl;
	cout << LeftRotateString(str1, 2) << endl;
	return 0;
}