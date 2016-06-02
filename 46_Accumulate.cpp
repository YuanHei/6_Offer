//求1+2+3+……+n
//方法一：构造函数

#include <iostream>
using namespace std;

class Temp
{
public:
	Temp()
	{
		//将累加放在构造函数中
		++N;
		Sum += N;
	}
	static void Reset()
	{
		//复位
		N = 0; 
		Sum = 0;
	}
	static unsigned int GetSum()
	{
		return Sum;
	}

private:
	static unsigned int N;
	static unsigned int Sum;
};

//静态成员初始化
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

//累加，调用构造函数
unsigned int Sum_Solution1(unsigned int n)
{
	Temp::Reset();

	Temp * a = new Temp[n];
	delete []a;
	a = NULL;

	return Temp::GetSum();
}

//方法二：利用虚函数求解
//当n不为零时，调用B::Sum，当n等于0时，调用函数A::Sum
class A;
A * Array[2];

class A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return 0;
	}
};

class B :public A
{
public:
	virtual unsigned int Sum(unsigned int n)
	{
		return Array[!!n]->Sum(n - 1) + n;
	}
};

int Sum_Solution2(int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);

	return value;
}

//方法三：利用函数指针求解
//原理与方法二相似
typedef unsigned int(*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n)
{
	return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
	static fun f[2] = { Solution3_Teminator, Sum_Solution3 };
	return n + f[!!n](n - 1);
}

//方法四：利用模板类型求解
//由于是一直递归执行，该过程是在编译过程中完成的，因此
//要求输入n必须是在编译期间就能确定的常量，不能动态输入
//而且编译器对递归编译的代码的递归深度是有限度的
//也就是要求n不能太大。

template<unsigned int n> 
struct Sum_Solution4 
{
	enum Value
	{
		N = Sum_Solution4<n-1>::N+n
	};
};

template<> 
struct Sum_Solution4<1>
{
	enum Value {N = 1};
};

//功能测试（输入5、10求1+2+3+……5和1+2+……+10）
//边界值测试（输入0和1）

int main()
{
	cout << Sum_Solution1(10) << endl;
	cout << Sum_Solution2(10) << endl;
	cout << Sum_Solution3(10) << endl;
	Sum_Solution4<10> sum;
	cout << sum.N << endl;


	return 0;
}